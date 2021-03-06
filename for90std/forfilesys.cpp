/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "forfilesys.h"
#include <map>

namespace for90std {
	static std::map<int, FILE *> filenos;
	static bool forfilesys_inited = false;
	FILE * get_file(int unit) {
		if (!forfilesys_inited) flush_fileno();
		auto iter = filenos.find(unit);
		if (iter != filenos.end()) {
			return iter->second;
		}
		return stdin;
		return stdout;
	}
	void flush_fileno() {
		filenos.clear();
		filenos[5] = stdin;
		filenos[6] = stdout;
		forfilesys_inited = true;
	}
	void foropenfile(int unit, std::string file, foroptional<std::string> access, foroptional<std::string> action, foroptional<std::string> status, foroptional<int> iostat, foroptional<std::string> form) {
		if (!forfilesys_inited) flush_fileno();
		using namespace std;
		bool docreate;
		bool doread;
		bool dowrite;
		bool doappend;
		string s;

		// method opertion(file attribute)
		// r read(r)
		// w write create/replace(w)
		// r+ read write(rw)
		// w+ read write create/replace(rw)
		// a append create(w)
		// a+ append create(rw)

		s = access.const_get();
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "append") {
			doappend = true;
		}
		else if (s == "sequential") {

		}
		else if (s == "direct") {

		}
		else {
			// not inited or else value
		}

		s = status.const_get();
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "new") {
			docreate = true;
		}else if(s == "replace"){
			docreate = true;
		}
		else if (s == "old") {
			docreate = false;
		}
		else if (s == "scratch") {
		}
		else {
			// not inited or else value
		}

		s = action.const_get();
		transform(s.begin(), s.end(), s.begin(), tolower);
		if (s == "read") {
			doread = true;
		}
		else if (s == "write") {
			dowrite = true;
		}
		else {
			doread = true;
			dowrite = true;
		}
		string mode;
		if (doappend) {
			mode = "a";
		}
		else {
			if (doread) {
				if (dowrite) {
					if (docreate) {
						mode = "w+";
					}
					else {
						mode = "r+";
					}
				}
				else {
					mode = "r";
				}
			}
			else {
				mode = "w";
			}
		}
		filenos[unit] = fopen(file.c_str(), mode.c_str());
	}
	void forclosefile(foroptional<int> unit, foroptional<std::string> status, foroptional<int> iostat) {
		if (!forfilesys_inited) flush_fileno();
		auto iter = filenos.find(unit.get());
		if (iter != filenos.end()) {
			fclose(iter->second);
		}
	}
}