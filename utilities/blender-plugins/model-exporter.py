bl_info = {
    "name": "Model Exporter",
    "description": "Export .model files from blender",
    "author": "xymostech",
    "version": (1, 0),
    "blender": (2, 66, 0),
    "location": "File > Import-Export",
    "warning": "",
    "wiki_url": "",
    "tracker_url": "",
    "category": "Import-Export",
}

import bpy

from bpy_extras.io_utils import (ExportHelper)

from bpy.props import (StringProperty,
                       )

def write_file(filepath):
    with open(filepath, 'w') as f:
        for o in bpy.data.meshes:
            f.write('object {0} {{\n'.format(o.name))
            f.write('\tverts {\n')
            for vert in o.vertices:
                f.write('\t\t{0} {1} {2};\n'.format(vert.co.x, vert.co.y, vert.co.z))
            f.write('\t}\n')
            f.write('\tindices {\n')
            for poly in o.polygons:
                first = True
                f.write('\t\t')
                for v in poly.vertices:
                    if first:
                        first = False
                    else:
                        f.write(' ')
                    f.write('{0}'.format(v))
                f.write(';\n')
            f.write('\t}\n')
            f.write('}\n')

class ModelExport(bpy.types.Operator, ExportHelper):
    """Test exporting stuff"""

    bl_idname = "export_scene.model"
    bl_label = '.model Export'
    bl_options = {'PRESET'}

    filename_ext = ".model"
    filter_glob = StringProperty(
        default="*.model",
        options={'HIDDEN'},
    )

    check_extension = True

    def execute(self, context):
        write_file(self.filepath)
        return {'FINISHED'}

def menu_func_export(self, context):
    self.layout.operator(ModelExport.bl_idname, text=".model Export")

def register():
    bpy.utils.register_module(__name__)

    bpy.types.INFO_MT_file_export.append(menu_func_export)

def unregister():
    bpy.utils.unregister_module(__name__)

    bpy.types.INFO_MT_file_export.remove(menu_func_export)

