import os
import sys
import importlib.machinery

from string import Template

def makedirs( dirs ):
    for dir in dirs:
        if not os.path.exists( dir ):
            os.mkdir( dir )
        elif os.path.isdir( dir ):
            print( 'Found existing directory: ' + dir )
        else:
            print( 'Cannot create directory due to name collision: ' + dir )

def makedirs_rec( dirs ):
    for dir in dirs:
        if not os.path.exists( dir ):
            os.makedirs( dir )
        elif os.path.isdir( dir ):
            print( 'Found existing directory: ' + dir )
        else:
            print( 'Cannot create directory due to name collision: ' + dir )

def script_path( script ):
    return os.path.join( os.path.dirname( os.path.realpath( __file__ ) ), script )

def template_path( template ):
    return os.path.join( os.path.dirname( os.path.realpath( __file__ ) ), 'templates', template )

def create_file_from_template( filepath, templatepath, mapping ):
    content = ''
    with open( templatepath ) as template_file:
        content = Template( template_file.read() ).substitute( mapping )
    with open( filepath, 'w' ) as output_file:
        output_file.write( content )

def import_from_path( name, path ):
    return importlib.machinery.SourceFileLoader( name, path ).load_module()
