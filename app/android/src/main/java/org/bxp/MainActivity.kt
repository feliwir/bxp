package org.bxp

import android.content.Context
import androidx.appcompat.app.AppCompatActivity

import android.os.Bundle
import android.opengl.GLSurfaceView

class MainActivity : AppCompatActivity() {

    private lateinit var gLView: GLSurfaceView

    public override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Create a GLSurfaceView instance and set it
        // as the ContentView for this Activity.
        gLView = BXPSurfaceView(this)
        setContentView(gLView)
    }
}