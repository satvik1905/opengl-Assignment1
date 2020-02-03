
#include "RenderWindow.h"


int main()
{
	RenderWindow *pWindow = new RenderWindow();

	bool bResultValue = pWindow->CreateRenderWindow(600, 400, "DrawTriangle...", true);
	if (!bResultValue)
		return 0;
	
	float pVertices[] = { -0.5f, -0.5f, 0.0f,         //Left Vertex Position
							0.5f, -0.5f, 0.0f,        //Right Vertex Position 
							0.0f, 0.5f, 0.0f		 //Middle Vertex Position
						};

	//Infinite Loop
	while (!glfwWindowShouldClose(pWindow->GetWindowHandle()))
	{
		if (glfwGetKey(pWindow->GetWindowHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(pWindow->GetWindowHandle(), true);

		glClearColor(0.7f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Render Triangle
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, pVertices);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableClientState(GL_VERTEX_ARRAY);

		glfwSwapBuffers(pWindow->GetWindowHandle());
		glfwPollEvents();
	}

	pWindow->Release();
	delete pWindow;

	return 0;
}