#pragma once
#include"Enemigo.h"
#include"Tanque.h"
#include"bala.h"
#include<vector>

using namespace std;

class Controlador
{
private:
	Tanque* tanque;
	vector<Enemigo*>enemigos;
	vector<Bala*>balas;
	int contador;
public:
	Controlador(Bitmap^ bmpTanque, Bitmap^ bmpEnemigo, Bitmap^ bmpBala) {
		//Inicio tanque:
		tanque = new Tanque(bmpTanque->Width / 3, bmpTanque->Height / 4);
		//Inicio enemigos:
		for (int i = 0; i < 0; i++) {
			crearEnemigo(bmpEnemigo);
		}
		for (int i = 0; i < 0; i++) {
			agregarBalas(bmpBala);
		}
		contador = 0;
	}
	~Controlador(){}

	//Añadir:
	void crearEnemigo(Bitmap^ bmpEnemigo) {
		enemigos.push_back(new Enemigo(bmpEnemigo->Width / 5, bmpEnemigo->Height / 3, rand() % 3));
	}

	void agregarBalas(Bitmap^ bmpBala) {
		balas.push_back(new Bala(tanque->getX(), tanque->getY(), bmpBala->Width, bmpBala->Height, tanque->getidY()));
	}
	//dibujar - mover
	void dibujarTODO(Graphics^ g, Bitmap^ bmpTanque, Bitmap^ bmpEnemigo, Bitmap^ bmpBala) {
		tanque->dibujar(g, bmpTanque);

		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->dibujar(g, bmpEnemigo);
		}
		for (int i = 0; i < balas.size(); i++) {
			balas[i]->dibujar(g, bmpBala);
		}
	}

	void moverTODO(Graphics^ g) {
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->movimientos(g);
		}

		for (int i = 0; i < balas.size(); i++) {
			balas[i]->movimientos(g);
		}

		
		
	}
	void collisiones(Graphics^ g) {

		for (int i = 0; i < balas.size(); i++) {
			if (balas[i]->getX() <= 0 || balas[i]->getXAncho() >= g->VisibleClipBounds.Width ||
				balas[i]->getY() <= 0 || balas[i]->getYAlto() >= g->VisibleClipBounds.Height) {
				balas[i]->setVisible(false);
			}
		}
	
		for (int i = 0; i < enemigos.size(); i++) {
		
			for (int j = 0; j < balas.size(); j++) {
				if (enemigos[i]->getRectangulo().IntersectsWith(balas[j]->getRectangulo())) {
					enemigos[i]->setVisible(false);
					balas[j]->setVisible(false);
				}


			}
		}

		
		for (int i = 0; i < enemigos.size(); i++) {
			if (!enemigos[i]->getVisible()) {
				enemigos.erase(enemigos.begin() + i);
				contador++;
			}
		}

		for (int i = 0; i < balas.size(); i++) {
			if (!balas[i]->getVisible()) {
				balas.erase(balas.begin() + i);
			}
		}

	
	}

	Tanque* getTanque() { return tanque; }

	int getContador() { return contador; }

};

