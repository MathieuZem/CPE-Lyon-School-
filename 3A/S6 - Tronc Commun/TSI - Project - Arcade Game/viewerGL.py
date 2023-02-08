#!/usr/bin/env python3

import OpenGL.GL as GL
from cpe3d import Text
from mesh import Mesh
import glutils
import glfw
import pyrr
import numpy as np
from math import *
from cpe3d import Object3D, Text, Transformation3D
import time
from random import random, randint


class ViewerGL:
    def __init__(self):
        # initialisation de la librairie GLFW
        glfw.init()
        # paramétrage du context OpenGL
        glfw.window_hint(glfw.CONTEXT_VERSION_MAJOR, 3)
        glfw.window_hint(glfw.CONTEXT_VERSION_MINOR, 3)
        glfw.window_hint(glfw.OPENGL_FORWARD_COMPAT, GL.GL_TRUE)
        glfw.window_hint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
        # création et paramétrage de la fenêtre
        glfw.window_hint(glfw.RESIZABLE, False)
        self.window = glfw.create_window(1280, 720, 'OpenGL', None, None)
        # paramétrage de la fonction de gestion des évènements
        glfw.set_key_callback(self.window, self.key_callback)
        # activation du context OpenGL pour la fenêtre
        glfw.make_context_current(self.window)
        glfw.swap_interval(1)
        # activation de la gestion de la profondeur
        GL.glEnable(GL.GL_DEPTH_TEST)
        # choix de la couleur de fond
        GL.glClearColor(0.5, 0.6, 0.9, 1.0)
        print(f"OpenGL: {GL.glGetString(GL.GL_VERSION).decode('ascii')}")

        self.objs = []
        self.touch = {}

        self.obstacle = []
        self.dx = 0
        self.start_timer_partie = 0
        self.start_time1s = 0
        self.seconds = 0
        self.minutes = 0
        self.score_int = 0
        self.max_vie = 3
        self.vie_restante = 3
        self.cut_touch = False
        self.fin_partie = True
        self.vao = Text.initalize_geometry()
        self.texture_text = glutils.load_texture('Ressource/Autre/fontmodif.png')
        self.programGUI_id = glutils.create_program_from_file('Shader/gui.vert', 'Shader/gui.frag')
        self.program3d_id = glutils.create_program_from_file('Shader/shader.vert', 'Shader/shader.frag')
        self.combo = 0
        self.streak = 0
        self.etat_colision = False

    def tick_1s(self):
        if int(time.time() - self.start_time1s) >= 1:
            self.start_time1s = time.time()
            self.Bonus()
            if self.start_timer_partie != 0 and self.fin_partie == False:
                self.temps()

            return True
        else:
            return False

    def add_obstacle(self, obstacle):
        self.obstacle.append(obstacle)

    def move_obj(self):

        for i in range(9):
            self.obstacle[i].transformation.translation.z -= self.dx
            if self.obstacle[i].transformation.translation.z <= -5:
                self.score()
                self.obstacle[i].transformation.translation.z += 270
                #print("S : écart entre ", i, "et", i-1, ":", self.obstacle[i].transformation.translation.z, "-", self.obstacle[i - 1].transformation.translation.z, "///", self.obstacle[i].transformation.translation.z - self.obstacle[i-1].transformation.translation.z)
                self.obstacle[i].transformation.rotation_euler[pyrr.euler.index().pitch] += i*(randint(0, 100))
                self.etat_colision = False

            else:
                if self.tick_1s() == True:

                    if self.seconds % 1 == 0 and self.dx != 0:
                        #print("augementation de vitesse itérer")
                        self.dx += 0.005

    def collision(self):

        for i in range(8):
            if self.obstacle[i].transformation.translation.z - 2 < self.objs[0].transformation.translation.z < self.obstacle[i].transformation.translation.z + 2:

                if self.etat_colision == False:
                    if (0+np.pi/11) % (2*np.pi) < self.obstacle[i].transformation.rotation_euler[1] % (2*np.pi) < ((0-np.pi/12) % (2*np.pi)):
                        #print("J'ai hit l'anneau", i)
                        malus = -1
                        self.vie(malus)
                        self.etat_colision = True
                        self.obstacle[i].transformation.translation.z = 270
                        self.etat_colision = False
                        self.combo = 0

    def mort(self):
        if self.vie_restante == 0:
                self.dx = 0
                self.fin_partie = True
                self.temps()
                self.score()
                self.vie(0)

    def Bonus(self):
        if self.streak % 10 == 0 and self.combo != 0:
            bonus = 1
            self.combo = 0
            if self.vie_restante == self.max_vie:
                self.max_vie += 1
            self.vie(bonus)

    def vie(self, stats_life):
        coeur = ''
        if self.fin_partie == False:
            self.vie_restante += stats_life

            for i in range(self.vie_restante):
                coeur += '#'
            for i in range(self.max_vie-self.vie_restante):
                coeur += '@'
            self.objs[12] = Text(coeur, np.array([-1, 0.8], np.float32), np.array([-0.7, 0.95], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

        else:
            self.objs[12] = Text(coeur, np.array([-1, 0.8], np.float32), np.array([-0.7, 0.95], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

    def temps(self):
        if self.fin_partie == False:
            self.seconds += 1
            if self.seconds % 60 == 0:
                self.minutes += 1
                self.seconds = 0
            seconds_str = str(self.seconds)
            minutes_str = str(self.minutes)
            time_str = minutes_str + ":" + seconds_str
            self.objs[13] = Text(time_str, np.array([-0.125, 0.8], np.float32), np.array([0.125, 0.95], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)
        else:
            seconds_str = str(self.seconds)
            minutes_str = str(self.minutes)
            time_str = minutes_str + ":" + seconds_str

            o = Text('TIME', np.array([-0.15, 0.3], np.float32), np.array([0.2, 0.5], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

            self.add_object(o)
            self.objs[13] = Text(time_str, np.array([-0.2, 0], np.float32), np.array([0.2, 0.3], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

    def score(self):
        self.combo += 1
        if self.fin_partie == False:
            self.score_int += 50 + 50 * self.streak
            score_str = str(self.score_int)
            self.objs[14] = Text(score_str, np.array([0.85, 0.8], np.float32), np.array([1, 0.95], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)
        else:
            o = Text('SCORE', np.array([-0.15, -0.2], np.float32), np.array([0.2, -0], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

            self.add_object(o)
            score_str = str(self.score_int)
            self.objs[14] = Text(score_str, np.array([-0.2, -0.5], np.float32), np.array([0.2, -0.2], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

            o = Text('PRESS "SPACE" TO RESTART', np.array([-0.8, -0.8], np.float32), np.array([0.8, -0.5], np.float32), self.vao, 2, self.programGUI_id, self.texture_text)

            self.add_object(o)
        self.streak += 1

    def reccreate_partie(self):

        self.objs = []
        self.touch = {}
        self.obstacle = []
        self.start_time1s = 0
        self.start_timer_partie = 0
        self.seconds = 0
        self.minutes = 0
        self.score_int = 0
        self.max_vie = 3
        self.vie_restante = 3
        self.fin_partie = False
        self.etat_colision = False
        self.dx = 0.15
        self.start_timer_partie = int(time.time())
        self.cut_touch = True
        self.streak = 0
        self.combo = 0

        m = Mesh.load_obj('Ressource/Voiture/Vroom.obj')
        m.normalize()
        m.apply_matrix(pyrr.matrix44.create_from_scale([1, 1, 1, 1]))
        tr = Transformation3D()
        tr.translation.y = -np.amin(m.vertices, axis=0)[1]
        tr.translation.z = 0
        tr.rotation_center.z = 0.2
        texture = glutils.load_texture('Ressource/Voiture/VC11_prototype00_col.png')
        o = Object3D(m.load_to_gpu(), m.get_nb_triangles(),self.program3d_id, texture, tr)
        self.add_object(o)

        m = Mesh.load_obj('Ressource/Environnement/cylindre.obj')
        m.normalize()
        m.apply_matrix(pyrr.matrix44.create_from_scale([7, 7, 310, 1]))
        tr = Transformation3D()
        tr.translation.x = 0
        tr.translation.z = -1
        tr.translation.y = 2
        tr.rotation_center.z = 0.0
        texture = glutils.load_texture('Ressource/Environnement/carre_blanc.png')
        o = Object3D(m.load_to_gpu(), m.get_nb_triangles(),self.program3d_id, texture, tr)
        self.add_object(o)

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
            tr.rotation_euler[pyrr.euler.index().pitch] += randint(0, 100)
            if i == 9:
                tr.rotation_euler[pyrr.euler.index().pitch] = 0

            o1 = Object3D(vao, m.get_nb_triangles(),self.program3d_id, texture, tr)
            self.add_object(o1)
            self.add_obstacle(o1)

        vao = Text.initalize_geometry()
        o = Text('###', np.array([-1, 0.8], np.float32), np.array([-0.7, 0.95], np.float32), vao, 2, self.programGUI_id, self.texture_text)
        self.add_object(o)
        o = Text('TIME', np.array([-0.125, 0.8], np.float32), np.array([0.125, 0.95], np.float32), vao, 2, self.programGUI_id, self.texture_text)
        self.add_object(o)
        o = Text('SCORE', np.array([0.7, 0.8], np.float32), np.array([1, 0.95], np.float32), vao, 2, self.programGUI_id, self.texture_text)
        self.add_object(o)

    def run(self):

        # boucle d'affichage
        while not glfw.window_should_close(self.window):
            # nettoyage de la fenêtre : fond et profondeur
            GL.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT)

            self.update_key()
            self.collision()
            self.move_obj()
            self.mort()

        # Paramètre de la Caméra sur le joueurs :
            self.cam.transformation.rotation_euler = -self.obstacle[9].transformation.rotation_euler.copy()
            self.cam.transformation.rotation_euler[pyrr.euler.index().yaw] += np.pi
            self.cam.transformation.translation = self.objs[0].transformation.translation + pyrr.Vector3([0, 1, 5])

            for obj in self.objs:
                GL.glUseProgram(obj.program)
                if isinstance(obj, Object3D):
                    self.update_camera(obj.program)
                obj.draw()

            # changement de buffer d'affichage pour éviter un effet de scintillement
            glfw.swap_buffers(self.window)
            # gestion des évènements
            glfw.poll_events()

    def key_callback(self, win, key, scancode, action, mods):
        # sortie du programme si appui sur la touche 'échappement'
        if key == glfw.KEY_ESCAPE and action == glfw.PRESS:
            glfw.set_window_should_close(win, glfw.TRUE)
        self.touch[key] = action

    def add_object(self, obj):
        self.objs.append(obj)

    def set_camera(self, cam):
        self.cam = cam

    def update_camera(self, prog):
        GL.glUseProgram(prog)
        # Récupère l'identifiant de la variable pour le programme courant
        loc = GL.glGetUniformLocation(prog, "translation_view")
        # Vérifie que la variable existe
        if (loc == -1):
            print("Pas de variable uniforme : translation_view")
        # Modifie la variable pour le programme courant
        translation = -self.cam.transformation.translation
        GL.glUniform4f(loc, translation.x, translation.y, translation.z, 0)

        # Récupère l'identifiant de la variable pour le programme courant
        loc = GL.glGetUniformLocation(prog, "rotation_center_view")
        # Vérifie que la variable existe
        if (loc == -1):
            print("Pas de variable uniforme : rotation_center_view")
        # Modifie la variable pour le programme courant
        rotation_center = self.cam.transformation.rotation_center
        GL.glUniform4f(loc, rotation_center.x,rotation_center.y, rotation_center.z, 0)

        rot = pyrr.matrix44.create_from_eulers(
            -self.cam.transformation.rotation_euler)
        loc = GL.glGetUniformLocation(prog, "rotation_view")
        if (loc == -1):
            print("Pas de variable uniforme : rotation_view")
        GL.glUniformMatrix4fv(loc, 1, GL.GL_FALSE, rot)

        loc = GL.glGetUniformLocation(prog, "projection")
        if (loc == -1):
            print("Pas de variable uniforme : projection")
        GL.glUniformMatrix4fv(loc, 1, GL.GL_FALSE, self.cam.projection)

    def update_key(self):
        if glfw.KEY_ENTER in self.touch and self.touch[glfw.KEY_ENTER] > 0:
            if self.cut_touch == False:
                self.dx = 0.15
                self.start_timer_partie = int(time.time())
                self.cut_touch = True
                self.fin_partie = False
                self.objs.pop()

        if glfw.KEY_A in self.touch and self.touch[glfw.KEY_A] > 0:
            if self.fin_partie == False:

                self.objs[1].transformation.rotation_euler[pyrr.euler.index().pitch] += 0.06
                for i in range(10):
                    self.obstacle[i].transformation.rotation_euler[pyrr.euler.index().pitch] += 0.06
        if glfw.KEY_D in self.touch and self.touch[glfw.KEY_D] > 0:
            if self.fin_partie == False:

                self.objs[1].transformation.rotation_euler[pyrr.euler.index().pitch] -= 0.06
                for i in range(10):
                    self.obstacle[i].transformation.rotation_euler[pyrr.euler.index().pitch] -= 0.06
                    
        if glfw.KEY_SPACE in self.touch and self.touch[glfw.KEY_SPACE] > 0:
            if self.fin_partie == True:
                self.reccreate_partie()