#include <c2d2/chien2d2lua.h>
#include <iostream>
#include <Game/SpaceGame.h>

using namespace std;

SpaceGame* game;

void setup()
{
	unsigned width = (unsigned)CL2_Double("largura_janela");
	unsigned height = (unsigned)CL2_Double("altura_janela");
	game = new SpaceGame(width, height);
}

void update(float secs)
{
	game->update(secs);
}

void draw()
{
	C2D2_LimpaTela();
	game->draw();
}

void dispose()
{
	delete game;
	game = NULL;
}

bool gameover(C2D2_Botao* teclas)
{
	return !game->isRunning()
		|| teclas[C2D2_ENCERRA].pressionado
		|| teclas[C2D2_F4].pressionado && teclas[C2D2_LALT].ativo;
}

int main(int argc, char* argv[])
{
	CL2_Inicia();
	if (!C2D2_Inicia("Game/config.lua"))
	{
		cout << "Não foi possível iniciar a Chien2D" << endl;
		exit(1);
	}
	
	setup();
	C2D2_Botao* teclas = C2D2_PegaTeclas();
	unsigned long antes = C2D2_TempoSistema()-1;
	while (!gameover(teclas))
	{
		float secs = (C2D2_TempoSistema() - antes) / 1000.0f;
		antes = C2D2_TempoSistema();
		update(secs);
		draw();
		C2D2_Sincroniza(C2D2_FPS_MAXIMO);
	}
	dispose();

	C2D2_Encerra();

	return 0;
}