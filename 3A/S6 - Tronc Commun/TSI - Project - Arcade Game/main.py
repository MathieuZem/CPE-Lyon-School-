from viewerGL import ViewerGL
import glutils
from mesh import Mesh
from cpe3d import Object3D, Camera, Transformation3D, Text
import numpy as np
import pyrr
import random


def main():
    viewer = ViewerGL()

    viewer.set_camera(Camera())
    viewer.cam.transformation.translation.y = 2
    viewer.cam.transformation.rotation_center = viewer.cam.transformation.translation.copy()
    viewer.cam.transformation.rotation_euler[pyrr.euler.index().yaw] += np.pi

    program3d_id = glutils.create_program_from_file('Shader/shader.vert', 'Shader/shader.frag')
    programGUI_id = glutils.create_program_from_file('Shader/gui.vert', 'Shader/gui.frag')

    m = Mesh.load_obj('Ressource/Voiture/Vroom.obj')
    m.normalize()
    m.apply_matrix(pyrr.matrix44.create_from_scale([1, 1, 1, 1]))
    tr = Transformation3D()
    tr.translation.y = -np.amin(m.vertices, axis=0)[1]
    tr.translation.z = 0
    tr.rotation_center.z = 0.2
    texture = glutils.load_texture('Ressource/Voiture/VC11_prototype00_col.png')
    o = Object3D(m.load_to_gpu(), m.get_nb_triangles(),program3d_id, texture, tr)
    viewer.add_object(o)

    m = Mesh.load_obj('Ressource/Environnement/cylindre.obj')
    m.normalize()
    m.apply_matrix(pyrr.matrix44.create_from_scale([7, 7, 310, 1]))
    tr = Transformation3D()
    tr.translation.x = 0
    tr.translation.z = -1
    tr.translation.y = 2
    tr.rotation_center.z = 0.0
    texture = glutils.load_texture('Ressource/Environnement/carre_blanc.png')
    o = Object3D(m.load_to_gpu(), m.get_nb_triangles(),program3d_id, texture, tr)
    viewer.add_object(o)

    m = Mesh.load_obj('Ressource/Environnement/obstacle.obj')
    m.normalize()
    m.apply_matrix(pyrr.matrix44.create_from_scale([2, 2, 1, 1]))
    texture = glutils.load_texture('Ressource/Environnement/carre_vert.jpg')
    vao = m.load_to_gpu()

    for i in range(10):

        tr = Transformation3D()
        tr.translation.z += i*30+30
        tr.translation.x = 0
        tr.translation.y = 2
        tr.rotation_center.y = -0.1
        tr.rotation_euler[pyrr.euler.index().pitch] += random.randint(0, 100)
        if i == 9:
            tr.rotation_euler[pyrr.euler.index().pitch] = 0

        o1 = Object3D(vao, m.get_nb_triangles(), program3d_id, texture, tr)
        viewer.add_object(o1)
        viewer.add_obstacle(o1)

    vao = Text.initalize_geometry()
    texture = glutils.load_texture('Ressource/Autre/fontmodif.png')
    o = Text('###', np.array([-1, 0.8], np.float32),np.array([-0.7, 0.95], np.float32), vao, 2, programGUI_id, texture)
    viewer.add_object(o)
    o = Text('TIME', np.array([-0.125, 0.8], np.float32), np.array([0.125, 0.95], np.float32), vao, 2, programGUI_id, texture)
    viewer.add_object(o)
    o = Text('SCORE', np.array([0.7, 0.8], np.float32), np.array([1, 0.95], np.float32), vao, 2, programGUI_id, texture)
    viewer.add_object(o)
    o = Text('PRESS "ENTER" TO START', np.array([-0.8, 0.3], np.float32), np.array([0.8, 0.5], np.float32), vao, 2, programGUI_id,texture)
    viewer.add_object(o)

    viewer.run()


if __name__ == '__main__':
    main()