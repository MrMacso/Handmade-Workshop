#ifndef TEXTURE_H
#define TEXTURE_H

/*==============================================================================================#
|                                                                                               |
| All code has been written by Karsten Vermeulen as part of the 'Handmade' game engine, for the |
| purposes of educating other fellow programmers, programming students and anyone else wishing  |
| to learn about game development, C++ and OOP. The engine, class design and overall structure  |
| is by no means perfect and there is certainly room for improvement. Feel free to use, copy,   |
| break, update and do as you wish with this code - it is there, free, for all!                 |
|																							    |
| Designed to teach. Made from scratch. Built by hand.  						                |
|																							    |
#===============================================================================================#
|																								|
| If you like 'Handmade', and wish to show your support, if you have any questions about the    |
| project, or if you just want to reach out, please find me on the following channels:          |
|																						        |
| Web: http://www.karstenvermeulen.com														    |
| Facebook: https://www.facebook.com/KarstensCorner								                |
| Twitter: https://twitter.com/KarstensCorner													|
| LinkedIn: https://www.linkedin.com/in/karstenvermeulen                                        |
| GitHub: https://github.com/djkarstenv									                        |
|                                                                                               |
#===============================================================================================#
| 'Texture' source files last updated in December 2019									        |
#==============================================================================================*/

#include <map>
#include <string>
#include "glad.h"

class Texture
{

public:

	Texture();

public:

	void SetTexture(const std::string& textureID);

public:

	bool Load(const std::string& filename, const std::string& textureID);
	void Bind();

public:

	void UnBind();
	void Unload();
	void Unload(const std::string& textureID);

public:

	void Output();

private:

	static std::map<std::string, GLuint>* s_textureIDMap;

private:

	GLuint m_ID;

};

#endif