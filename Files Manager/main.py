import shutil
import json
import os


def move_file(file, destination):
    try:
        if not os.path.exists(destination):
            os.makedirs(destination)
        shutil.move(file, destination)

    except shutil.Error as e:
        print(e)


def sort_folder(folder_path):

    with open('config.json', encoding='utf-8') as config:
        categories = json.load(config)

    extensions = {}
    for category in categories:
        folder_name = category['name']

        for extension in category['extensions']:
            extensions[extension] = folder_name

    for file in os.listdir(folder_path):

        if os.path.isfile(os.path.join(downloads_path, file)) and not file.startswith('.') and not file == 'desktop.ini':

            _, file_ext = os.path.splitext(file)
            destination = os.path.join(downloads_path, extensions.get(file_ext, 'Other'))
            move_file(os.path.join(downloads_path, file), os.path.join(downloads_path, destination))


if __name__ == '__main__':
    downloads_path = "C:\\Users\\user\\Downloads"

    sort_folder(downloads_path)