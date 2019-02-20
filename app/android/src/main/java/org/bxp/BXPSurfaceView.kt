package org.bxp

import android.opengl.GLSurfaceView
import android.content.Context

class BXPSurfaceView(context: Context) : GLSurfaceView(context) {

    private val renderer: BXPRenderer

    init {

        // Create an OpenGL ES 2.0 context
        setEGLContextClientVersion(2)

        renderer = BXPRenderer()

        // Set the Renderer for drawing on the GLSurfaceView
        setRenderer(renderer)
    }
}

