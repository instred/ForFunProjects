# folder-automation
Automate your folders on window by file types.

This script iterates through the files in the choosen folder and moves them to their respective sub-folders. If the 
sub-folder does not exist, it is created then the files moved into it.

Sciript uses os and shutil to manage the files and json to manage the config file for easier sub-folder changes.

## Prerequisites
This script requires Python to be installed for it to run. To install Python, click [here](https://www.python.org/downloads/).

## Usage
From a terminal, navigate into the project directory.
```
$ cd '.\Files Manager\'
```
To run the script:
```
$ python main.py