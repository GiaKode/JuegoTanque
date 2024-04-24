#pragma once
#include <iostream>
using namespace System;
using namespace System::Drawing;


class Movimientos
{
protected:
	int x, y;
	int ancho, alto;
	int dx, dy;
	int idX, idY;
	bool visible;

public:
	Movimientos(int ancho, int alto) {

		
		this->ancho = ancho;
		this->alto = alto;
		idX = idY = 0;
		visible = true;

	}
	~Movimientos() {};

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * ancho, idY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void movimientos() {}

	Rectangle getRectangulo() {
		return Rectangle(x, y, ancho * 1.0, alto * 1.0);
	}

	int getX() { return x+40; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	int getidY() { return idY; }
	int getidX() { return idX; }
};

