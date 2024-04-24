#pragma once
#include "Movimientos.h"

class Bala : public Movimientos {
private:
	int direccion;

public:
	Bala(int x, int y, int ancho, int alto, int direccion) : Movimientos(ancho, alto) {
		this->x = x;
		this->y = y;
		this->direccion = direccion;
		dx = 10;
		dy = 10;
	}

	~Bala() {}
	void movimientos(Graphics^ g) {
		if (direccion == 0 && y + alto * 1.0 <= g->VisibleClipBounds.Height) {
			y += dy;
		}
		if (direccion == 3 && y >= 0) {
			y -= dy;
		}
		if (direccion == 2 && x + ancho * 1.0 <= g->VisibleClipBounds.Width) {
			x += dx;
		}
		if (direccion == 1 && x >= 0) {
			x -= dx;
		}
		





	}

	
	int getX() { return x; }
	int getY() { return y; }
	int getXAncho() { return x + ancho * 1.0; }
	int getYAlto() { return y + alto * 1.0; }
};