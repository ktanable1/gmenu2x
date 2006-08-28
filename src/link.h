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
#ifndef LINK_H
#define LINK_H

#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "surface.h"

using std::string;

/**
Parses links files.

	@author Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
*/
class Link {
private:
	string path, sclock;
	int iclock;
	bool edited;
	string title, description, exec, params, icon, workdir;

public:
	Link(string path, const char* linkfile);

	string getTitle();
	void setTitle(string title);
	string getDescription();
	void setDescription(string description);
	string getExec();
	void setExec(string exec);
	string getParams();
	void setParams(string params);
	string getIcon();
	void setIcon(string icon);
	string getWorkdir();
	void setWorkdir(string workdir);

	string file;
	int clock();
	string clockStr();
	void setClock(int);

	bool wrapper;
	bool dontleave;

	bool save();
	void run();
	bool targetExists();
};

#endif