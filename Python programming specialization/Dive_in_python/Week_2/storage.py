import os
import json
import tempfile
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--key')
parser.add_argument('--val')

args = parser.parse_args()

storage_path = os.path.join(
    tempfile.gettempdir(), 'storage.data'
)

data = {}

if os.path.exists(storage_path):

    with open(storage_path, 'r') as f:
    
        json_text = f.read()

        if json_text != "":
            data = json.loads(json_text)
    
if args.key and args.val:
    
    with open(storage_path, 'w') as f:
        
        if args.key in data:
            data[args.key].append(args.val)
        else:
            data[args.key] = [args.val]
    
        f.write(json.dumps(data))

else: 
    print(data.get(args.key))
