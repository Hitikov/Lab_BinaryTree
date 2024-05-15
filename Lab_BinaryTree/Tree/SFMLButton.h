#pragma once

#include "SFML/Graphics.hpp"
#include "WorkMode.h"

#include <vector>

using namespace sf;
using namespace std;

class SFMLButton
{
public:
	SFMLButton(RectangleShape& shape, Vector2f position, string text, WorkMode mode, RenderWindow& window)
	{
		Shape.setSize(shape.getSize());

		Shape.setPosition(position);

		Shape.setFillColor(shape.getFillColor());

		window.draw(Shape);

		Text line;
		Font font;

		font.loadFromFile("CyrilicOld.TTF");
		line.setFont(font);

		line.setString(text);
		line.setFillColor(Color::Black);
		line.setOutlineColor(Color::White);
		line.setCharacterSize(20);

		line.setPosition(Vector2f(position.x, position.y));

		window.draw(line);

		Mode = mode;
	};

	static void SetUpButtons(float Y, float startX, float XDyff, vector<SFMLButton>& AddTo, RenderWindow& window,
		int activeButtonIndex)
	{
		int x = startX - XDyff;

		for (int i = 0; i < 6; i++)
		{
			string text;
			WorkMode mode;

			x += XDyff;

			switch (i)
			{
			case 0:
				text = "Добавить вершину";
				mode = WorkMode::CreateVertex;
				break;
			case 1:
				text = "Удалить вершину";
				mode = WorkMode::DestroyVertex;
				break;
			case 2:
				text = "Подвинуть вершину";
				mode = WorkMode::MoveVertex;
				break;
			case 3:
				text = "Добавить ребро";
				mode = WorkMode::CreateEdge;
				break;
			case 4:
				text = "Удалить ребро";
				mode = WorkMode::DestroyEdge;
				break;
			case 5:
				text = "Решить задачу";
				mode = WorkMode::MerchantProblem;
				break;
			default:
				break;
			}

			RectangleShape shape(Vector2f(180, 30));

			if (i == activeButtonIndex)
				shape.setFillColor(Color::Cyan);

			AddTo.push_back(SFMLButton(shape, Vector2f(Y, x), text, mode, window));
		}
	}

	RectangleShape& getShape()
	{
		return Shape;
	}

	WorkMode GetWorkMode()
	{
		return Mode;
	}

private:

	WorkMode Mode;

	RectangleShape Shape;
};
