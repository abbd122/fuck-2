import os
import re

ALLOW_EXTS = {'.cpp', '.cc', '.c', '.h', '.py'}


def all_files(dir_path):
    for root, dirs, files in os.walk(dir_path):
        for file in files:
            file_path = os.path.join(root, file)
            if (os.path.splitext(file_path)[1] in ALLOW_EXTS):
                yield file_path


def find_line(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        for eachline in file:
            if re.match(match_str, eachline.replace(' ', '')):
                print(file_path)
                return


if __name__ == '__main__':
    match_str = input()
    for file_path in all_files(os.curdir):
        find_line(file_path)
    a = input()
