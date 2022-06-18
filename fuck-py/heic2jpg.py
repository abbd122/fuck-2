import os, subprocess

directory = '.'

for filename in os.listdir(directory):
    if filename.lower().endswith(".heic"):
        file_path = os.path.join(directory, filename)
        print(file_path)
        subprocess.run(["magick", "%s" % file_path, "%s" % (filename[0:-5] + '.jpg')])
        continue