import os
import subprocess
import argparse
import shutil

print 'Protocol Buffer Builder'

def prepare_output_directory(path):
	shutil.rmtree(path, ignore_errors=True) # remove existing folder
	if not os.path.isdir(path): # create folder
		os.mkdir(path)

# read input args
parser = argparse.ArgumentParser(description='')
parser.add_argument('--cpp', action='store_true')
parser.add_argument('--csharp', action='store_true')
parser.add_argument('--java', action='store_true')
parser.add_argument('--javanano', action='store_true')
parser.add_argument('--objc', action='store_true')
parser.add_argument('--python', action='store_true')
parser.add_argument('--ruby', action='store_true')
args = parser.parse_args()

# are all args false?
all_false = not (True in vars(args).values())

# dictionary of flags to use based on input
lang_flags = {}
if args.cpp or all_false:
	lang_flags['cpp'] = '--cpp_out=cpp'
	prepare_output_directory('cpp')
if args.csharp or all_false:
	lang_flags['csharp'] = '--csharp_out=cs'
	prepare_output_directory('cs')
if args.java or all_false:
	lang_flags['java'] = '--java_out=java'
	prepare_output_directory('java')
#if args.javanano or all_false:
#	lang_flags['javanano'] = '--javanano_out=javanano'
#	prepare_output_directory('javanano')
if args.objc or all_false:
	lang_flags['objc'] = '--objc_out=objc'
	prepare_output_directory('objc')
if args.python or all_false:
	lang_flags['python'] = '--python_out=py'
	prepare_output_directory('py')
if args.ruby or all_false:
	lang_flags['ruby'] = '--ruby_out=rb'
	prepare_output_directory('rb')

# get all files to convert
proto_path = 'src'
proto_ext = '.proto'
proto_files = [os.path.join(dirpath, f) for dirpath, dirnames, files in os.walk(proto_path) for f in files if f.endswith(proto_ext)]

# flags for subprocess
protoc_args = ['protoc.exe', '-Isrc', 'CHANGE_ME', None]

# process all language flags
for curr_flag in lang_flags:
	print 'building ' + str(curr_flag) + '...',
	for curr_file in proto_files:
		protoc_args[-1] = curr_file # file is the last argument
		protoc_args[-2] = lang_flags[curr_flag]
		subprocess.Popen(protoc_args)
	print 'done!'
