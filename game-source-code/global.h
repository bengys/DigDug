#ifndef GLOBAL_H
#define GLOBAL_H

enum class Direction { left, right, up, down };
enum class BlockType { solid, empty };

namespace arrVars
{
const unsigned int SCREENWIDTH = 1280; // 512;
const unsigned int SCREENHEIGHT = 720; // 256;
const float BLOCKSIZE = 20; // 16;
const unsigned int TOPARRAYSPACE = 3;
const unsigned int ARRAYLENGTH = SCREENWIDTH / BLOCKSIZE;
const unsigned int ARRAYBREADTH = (SCREENHEIGHT / BLOCKSIZE) - TOPARRAYSPACE;
const unsigned int TOPSPACE = TOPARRAYSPACE * BLOCKSIZE;
};

#endif
