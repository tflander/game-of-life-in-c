import os 
import shutil 

game_of_life_source_code_path = "src/"
arduino_lib_target = "/Users/todd.a.flanders/Documents/Arduino/libraries/gameOfLife"

print("deploying source to Arduino lib") 
source_code_folder = os.listdir(game_of_life_source_code_path)
source_code_folder

for source_file in source_code_folder:
    src = game_of_life_source_code_path + source_file
    src
    dest = arduino_lib_target + '/' + source_file
    dest
    shutil.copyfile(src, dest) 

print("done.") 
