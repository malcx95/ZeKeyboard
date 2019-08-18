import bpy
import json
import bmesh
from bpy import context

FILE_NAME = "layout.json"

# distance between switches in mm
STANDARD_SWITCH_DISTANCE = 18.5

# The width of each switch in mm
SWITCH_WIDTH = 14.4

# The width of the border around the switch
SWITCH_PADDING = 1.0

SWITCH_PLATE_THICKNESS = 1.5

# The vertices of a switch hole, in the order they are to be joined
SWITCH_HOLE = [(0, 0), (1, 0), (1, 1), (0, 1)]

def load_layout():
    with open(FILE_NAME) as f:
        return json.load(f)


def create_switch_hole(x, y, name):

    switch_name = "Switch: " + name
    mesh = bpy.data.meshes.new("mesh")
    obj = bpy.data.objects.new(switch_name, mesh)

    scene = bpy.context.scene
    scene.objects.link(obj)
    scene.objects.active = obj
    obj.select = True

    mesh = bpy.context.object.data
    bm = bmesh.new()

    if hasattr(bm.verts, "ensure_lookup_table"): 
        bm.verts.ensure_lookup_table()
        bm.edges.ensure_lookup_table()
    
    # create the lower and upper vertices of the thinner switch hole
    for vx, vy in SWITCH_HOLE:
        bm.verts.new((vx*SWITCH_WIDTH, vy*SWITCH_WIDTH, 0))
        # bm.verts.new((vx*SWITCH_WIDTH, vy*SWITCH_WIDTH, 
        #               SWITCH_PLATE_THICKNESS))

    
    
    # connect the vertices 
    for i in range(4):

        bm.verts.ensure_lookup_table()
        bm.edges.ensure_lookup_table()

        # even indices are the lower vertices, odd are the upper ones
        bm.edges.new((bm.verts[i], bm.verts[(i + 1) % 4]))
        
        # bm.edges.new((bm.verts[i*2], bm.verts[(i + 1)*2 % 8]))
        
        # bm.verts.ensure_lookup_table()
        # bm.edges.ensure_lookup_table()

        # bm.edges.new((bm.verts[(i*2 + 1) % 8], 
        #               bm.verts[((i + 1)*2 + 1) % 8]))

        # bm.verts.ensure_lookup_table()
        # bm.edges.ensure_lookup_table()

        # # connect the top and bottom vertices
        # bm.edges.new((bm.verts[i*2], bm.verts[i*2 + 1]))

    bm.to_mesh(mesh)
    bm.free()

    # extrude

    scene.objects.active = obj
    obj.select = True
    bpy.ops.object.mode_set(mode='EDIT')
    bpy.ops.mesh.select_mode(type ='VERT')
    bpy.ops.mesh.select_all(action='SELECT')

    bpy.ops.mesh.extrude_region_move(
        TRANSFORM_OT_translate={"value":(0, 0, SWITCH_PLATE_THICKNESS)})

    bpy.ops.object.mode_set(mode='OBJECT')

if __name__ == "__main__":
    create_switch_hole(0, 0, "test")

