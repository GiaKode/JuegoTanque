#pragma once
#include"Movimientos.h"


class Enemigo : public Movimientos
{
private:
	int direcciones;
public:
	Enemigo(int ancho, int alto, int direcciones) :Movimientos(ancho, alto) {
		this->direcciones = direcciones;
		x = rand() % 30 * 20;
		y = rand() % 50 * 10;
		dx = dy = 9;
		idX = rand() % 6;
		idY = rand() % 3;

	}
	~Enemigo() {}

	void movimientos(Graphics^ g) {

		if (direcciones == 1)
		{
			if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0)
				dx *= -1;
			
			x += dx;
		}
		else
		{
			if (y + alto * 1.0 > g->VisibleClipBounds.Height || y < 0)
				dy *= -1;
			y += dy;
		}
		
	}



};