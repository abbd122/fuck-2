import os, datetime
from string import digits

from PIL import Image


def main():
    file_name_dict = {os.path.splitext(file)[0]: file for file in os.listdir('.')}
    pic_list = []
    total_height = 0
    for i in digits:
        if not i in file_name_dict.keys():
            continue
        pic = Image.open(os.path.join('.', file_name_dict[i]))
        total_height += pic.size[1]
        pic_list.append(pic)
    res = Image.new(pic_list[0].mode, (pic_list[0].size[0], total_height))
    height = 0
    for pic in pic_list:
        res.paste(pic, box=(0, height))
        height += pic.size[1]
    now = datetime.datetime.now().strftime('%Y%m%d%H%M%S')
    merge_path = os.path.join('.', 'merge_' + now + '.png')
    res.save(merge_path)


if __name__ == '__main__':
    main()
