import os 
import shutil 

game_of_life_source_code_path = "src/"
arduino_folder = "/Users/todd.a.flanders/Documents/Arduino/"
arduino_lib_target = arduino_folder + "libraries/gameOfLife"
sketch_source = arduino_folder + "GameOfLifeTdd"

print("deploying source to Arduino lib") 
source_code_folder = os.listdir(game_of_life_source_code_path)
source_code_folder

for source_file in source_code_folder:
    src = game_of_life_source_code_path + source_file
    src
    dest = arduino_lib_target + '/' + source_file
    dest
    shutil.copyfile(src, dest) 

print("copying Arduino sketch into git workspace") 
shutil.copyfile(sketch_source + "/GameOfLifeTdd.ino", "./GameOfLifeTdd.ino") 

print("done.") 
