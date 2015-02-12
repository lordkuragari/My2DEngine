#include "framework.h"

GLF TwoDEngine;

int main()
{
	TwoDEngine.InitWindow(1024, 720, "Hell YA!!");

	float x, y;
	x = y = 400;
	float speed = 250.f;

	unsigned int s = TwoDEngine.CreateSprite("resources\\images\\Astroid.png", 32, 32);
	TwoDEngine.CreateAnimation("resources\\images\\vegeta_walking\\VegetaSprites.xml", walking, 16, 32);

	animate boku;
	animate begeta;

	while (TwoDEngine.UpdateFramework())
	{
		TwoDEngine.SetScreenColor(0.1f, 0.4f, 0.7f, 0.0f);
	
		x += speed * TwoDEngine.hDirection * TwoDEngine.deltaTime;
		y += speed * TwoDEngine.vDirection * TwoDEngine.deltaTime;

		TwoDEngine.MoveSprite(s, x, y);
		TwoDEngine.DrawSprite(s);

		TwoDEngine.DrawAnimatedSprite(walking);
		TwoDEngine.SwapBuffers();

		if (glfwGetKey(TwoDEngine.window, GLFW_KEY_W))
		{
			boku.PlayAnimation(walking);
		}
	}

	TwoDEngine.Shutdown();
}