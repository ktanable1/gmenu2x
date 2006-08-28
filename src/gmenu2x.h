/***************************************************************************
 *   Copyright (C) 2006 by Massimiliano Torromeo   *
 *   massimiliano.torromeo@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef GMENU2X_H
#define GMENU2X_H

#include <string>
#include <iostream>
#include "menu.h"
#include "surfacecollection.h"
#include "FastDelegate.h"

#ifdef TARGET_GP2X
#include "joystick.h"
#endif

#define BATTERY_READS 10

using std::string;
using fastdelegate::FastDelegate0;

typedef FastDelegate0<> MenuAction;

struct MenuOption {
	string text;
	MenuAction action;
};

class GMenu2X {
private:
	string path;
	string getExePath();
	string getDiskFree();
	unsigned short cpuX, batX;
	void drawRun();
	void drawScrollBar(uint pagesize, uint totalsize, uint pagepos, uint top, uint height);
	void setClock(int mhz);
	unsigned short getBatteryLevel();
	void browsePath(string path, vector<string>* directories, vector<string>* files);
	void createLink(string path, string file);
	void readConfig();
	void writeConfig();
	void setInputSpeed();

public:
	GMenu2X(int argc, char *argv[]);
	~GMenu2X();

#ifdef TARGET_GP2X
	Joystick joy;
#else
	SDL_Event event;
#endif

	int alphablend, colorR, colorG, colorB;
	SurfaceCollection sc;
	Surface *s;
	SFont *font;

	//Status functions
	int main();
	void options();
	void contextMenu();
	void fileBrowser();

	void runLink();
	void deleteLink();
	void renameLink();
	void editDescriptionLink();

	void initBG();
	void write(SDL_Surface *s, string text, int x, int y);
	void writeCenter(SDL_Surface *s, string text, int x, int y);

	Menu* menu;
};

#endif