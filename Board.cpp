/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include "Board.hpp"

// Contains all hextiles
vector<Hextile> Board::block;

// Initializes the board and sets up the hextiles.
Board::Board()
{
    init();
}

/**
 * This is a factory method - the hextiles are created in the for loop and pushed into vector.
 * After the initialization every node of the hextile created according to it's position on the board.
 */
void Board::init()
{
    for (int i = 0; i < 19; i++)
    {
        Hextile hex = Hextile();
        block.push_back(hex);
    }

    for (int i = 0; i < 19; i++)
    {
        if (block[i].serial == 0)
        {
            block[i].n = new node(&block[0], NULL, NULL);
            block[i].nw = new node(&block[0], NULL, NULL);
            block[i].ne = new node(&block[0], &block[1], NULL);
            block[i].se = new node(&block[0], &block[1], &block[4]);
            block[i].s = new node(&block[0], &block[3], &block[4]);
            block[i].sw = new node(&block[0], &block[3], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 1)
        {
            block[i].nw = new node(&block[1], &block[0], NULL);
            block[i].sw = new node(&block[1], &block[0], &block[4]);
            block[i].n = new node(&block[1], NULL, NULL);
            block[i].ne = new node(&block[1], &block[2], NULL);
            block[i].se = new node(&block[1], &block[2], &block[5]);
            block[i].s = new node(&block[1], &block[4], &block[5]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 2)
        {
            block[i].nw = new node(&block[2], &block[1], NULL);
            block[i].sw = new node(&block[2], &block[1], &block[5]);
            block[i].n = new node(&block[2], NULL, NULL);
            block[i].ne = new node(&block[2], NULL, NULL);
            block[i].s = new node(&block[2], &block[5], &block[6]);
            block[i].se = new node(&block[2], &block[6], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 3)
        {
            block[i].n = new node(&block[3], &block[0], NULL);
            block[i].ne = new node(&block[3], &block[0], &block[4]);
            block[i].nw = new node(&block[3], NULL, NULL);
            block[i].se = new node(&block[3], &block[4], &block[8]);
            block[i].s = new node(&block[3], &block[7], &block[8]);
            block[i].sw = new node(&block[3], &block[7], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 4)
        {
            block[i].n = new node(&block[4], &block[0], &block[1]);
            block[i].ne = new node(&block[4], &block[1], &block[5]);
            block[i].nw = new node(&block[4], &block[1], &block[3]);
            block[i].se = new node(&block[4], &block[5], &block[9]);
            block[i].s = new node(&block[4], &block[8], &block[9]);
            block[i].sw = new node(&block[4], &block[3], &block[8]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 5)
        {
            block[i].n = new node(&block[5], &block[1], &block[2]);
            block[i].nw = new node(&block[5], &block[1], &block[4]);
            block[i].ne = new node(&block[5], &block[2], &block[6]);
            block[i].se = new node(&block[5], &block[6], &block[10]);
            block[i].s = new node(&block[5], &block[9], &block[10]);
            block[i].sw = new node(&block[5], &block[4], &block[9]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }

        if (block[i].serial == 6)
        {
            block[i].n = new node(&block[6], &block[2], NULL);
            block[i].nw = new node(&block[6], &block[2], &block[5]);
            block[i].ne = new node(&block[6], NULL, NULL);
            block[i].se = new node(&block[6], &block[11], NULL);
            block[i].s = new node(&block[6], &block[10], &block[11]);
            block[i].sw = new node(&block[6], &block[5], &block[10]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }

        if (block[i].serial == 7)
        {
            block[i].n = new node(&block[7], &block[3], NULL);
            block[i].ne = new node(&block[7], &block[3], &block[8]);
            block[i].nw = new node(&block[7], NULL, NULL);
            block[i].sw = new node(&block[7], NULL, NULL);
            block[i].se = new node(&block[7], &block[8], &block[12]);
            block[i].s = new node(&block[7], &block[12], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 8)
        {
            block[i].n = new node(&block[8], &block[3], &block[4]);
            block[i].nw = new node(&block[8], &block[3], &block[7]);
            block[i].ne = new node(&block[8], &block[4], &block[9]);
            block[i].se = new node(&block[8], &block[9], &block[13]);
            block[i].s = new node(&block[8], &block[12], &block[13]);
            block[i].sw = new node(&block[8], &block[7], &block[12]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 9)
        {
            block[i].n = new node(&block[9], &block[4], &block[5]);
            block[i].nw = new node(&block[9], &block[4], &block[8]);
            block[i].ne = new node(&block[9], &block[5], &block[10]);
            block[i].se = new node(&block[9], &block[10], &block[14]);
            block[i].s = new node(&block[9], &block[13], &block[14]);
            block[i].sw = new node(&block[9], &block[8], &block[13]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 10)
        {
            block[i].n = new node(&block[10], &block[5], &block[6]);
            block[i].nw = new node(&block[10], &block[6], &block[11]);
            block[i].ne = new node(&block[10], &block[5], &block[9]);
            block[i].se = new node(&block[10], &block[11], &block[15]);
            block[i].s = new node(&block[10], &block[14], &block[15]);
            block[i].sw = new node(&block[10], &block[9], &block[14]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 11)
        {
            block[i].n = new node(&block[11], &block[6], NULL);
            block[i].nw = new node(&block[11], &block[10], &block[6]);
            block[i].ne = new node(&block[11], NULL, NULL);
            block[i].se = new node(&block[11], NULL, NULL);
            block[i].s = new node(&block[11], &block[15], NULL);
            block[i].sw = new node(&block[11], &block[10], &block[15]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 12)
        {
            block[i].n = new node(&block[12], &block[7], &block[8]);
            block[i].nw = new node(&block[12], &block[7], NULL);
            block[i].sw = new node(&block[12], NULL, NULL);
            block[i].ne = new node(&block[12], &block[8], &block[13]);
            block[i].se = new node(&block[12], &block[13], &block[16]);
            block[i].s = new node(&block[12], &block[16], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 13)
        {
            block[i].n = new node(&block[13], &block[8], &block[9]);
            block[i].nw = new node(&block[13], &block[8], &block[12]);
            block[i].ne = new node(&block[13], &block[9], &block[14]);
            block[i].se = new node(&block[13], &block[14], &block[17]);
            block[i].s = new node(&block[13], &block[16], &block[17]);
            block[i].sw = new node(&block[13], &block[12], &block[16]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 14)
        {
            block[i].n = new node(&block[14], &block[9], &block[10]);
            block[i].nw = new node(&block[14], &block[9], &block[13]);
            block[i].ne = new node(&block[14], &block[15], &block[10]);
            block[i].se = new node(&block[14], &block[15], &block[18]);
            block[i].s = new node(&block[14], &block[17], &block[18]);
            block[i].sw = new node(&block[14], &block[13], &block[17]);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 15)
        {
            block[i].n = new node(&block[15], &block[10], &block[11]);
            block[i].nw = new node(&block[15], &block[10], &block[14]);
            block[i].ne = new node(&block[15], &block[11], NULL);
            block[i].se = new node(&block[15], NULL, NULL);
            block[i].s = new node(&block[15], &block[18], NULL);
            block[i].sw = new node(&block[15], &block[14], &block[18]);
            ;
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 16)
        {
            block[i].n = new node(&block[16], &block[13], &block[12]);
            block[i].nw = new node(&block[16], &block[12], NULL);
            block[i].ne = new node(&block[16], &block[17], &block[13]);
            block[i].s = new node(&block[16], NULL, NULL);
            block[i].sw = new node(&block[16], NULL, NULL);
            block[i].se = new node(&block[16], &block[17], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 17)
        {
            block[i].n = new node(&block[17], &block[14], &block[13]);
            block[i].nw = new node(&block[17], &block[16], &block[13]);
            block[i].ne = new node(&block[17], &block[18], &block[14]);
            block[i].se = new node(&block[17], &block[18], NULL);
            block[i].s = new node(&block[17], NULL, NULL);
            block[i].sw = new node(&block[17], &block[16], NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
        if (block[i].serial == 18)
        {
            block[i].n = new node(&block[18], &block[15], &block[14]);
            block[i].nw = new node(&block[18], &block[17], &block[14]);
            block[i].ne = new node(&block[18], &block[15], NULL);
            block[i].sw = new node(&block[18], &block[17], NULL);
            block[i].se = new node(&block[18], NULL, NULL);
            block[i].s = new node(&block[18], NULL, NULL);
            block[i].n->neighbor = block[i].ne;
            block[i].ne->neighbor = block[i].se;
            block[i].se->neighbor = block[i].s;
            block[i].s->neighbor = block[i].sw;
            block[i].sw->neighbor = block[i].nw;
            block[i].nw->neighbor = block[i].n;
        }
    }
    setRelatedBlocks();
}

// Setting the equal nodes
void Board::setRelatedBlocks()
{
    for (int i = 0; i < 19; i++)
    {
        if (block[i].serial == 0)
        {
            block[i].ne->equals1 = block[1].nw;
            block[i].se->equals1 = block[1].sw;
            block[i].se->equals2 = block[4].n;
            block[i].s->equals1 = block[3].ne;
            block[i].s->equals2 = block[4].nw;
            block[i].sw->equals1 = block[3].n;
        }
        if (block[i].serial == 1)
        {
            block[i].nw->equals1 = block[0].ne;
            block[i].ne->equals1 = block[2].nw;
            block[i].se->equals1 = block[2].sw;
            block[i].se->equals2 = block[5].n;
            block[i].s->equals1 = block[4].ne;
            block[i].s->equals2 = block[5].nw;
            block[i].sw->equals1 = block[0].se;
            block[i].sw->equals2 = block[4].n;
        }
        if (block[i].serial == 2)
        {
            block[i].se->equals1 = block[6].n;
            block[i].s->equals1 = block[5].ne;
            block[i].s->equals2 = block[6].nw;
            block[i].sw->equals1 = block[5].n;
            block[i].sw->equals2 = block[1].se;
            block[i].nw->equals1 = block[1].ne;
        }
        if (block[i].serial == 3)
        {
            block[i].n->equals1 = block[0].sw;
            block[i].ne->equals1 = block[0].s;
            block[i].ne->equals2 = block[4].nw;
            block[i].se->equals1 = block[4].sw;
            block[i].se->equals2 = block[8].n;
            block[i].s->equals1 = block[7].nw;
            block[i].s->equals2 = block[8].ne;
            block[i].sw->equals1 = block[7].n;
        }
        if (block[i].serial == 4)
        {
            block[i].n->equals1 = block[0].se;
            block[i].n->equals2 = block[1].sw;
            block[i].ne->equals1 = block[1].s;
            block[i].ne->equals2 = block[5].nw;
            block[i].se->equals1 = block[5].sw;
            block[i].se->equals2 = block[9].n;
            block[i].s->equals1 = block[8].ne;
            block[i].s->equals2 = block[9].nw;
            block[i].sw->equals1 = block[3].se;
            block[i].sw->equals2 = block[8].n;
            block[i].nw->equals1 = block[0].s;
            block[i].nw->equals2 = block[3].ne;
        }
        if (block[i].serial == 5)
        {
            block[i].n->equals1 = block[1].se;
            block[i].n->equals2 = block[2].sw;
            block[i].ne->equals1 = block[2].s;
            block[i].ne->equals2 = block[6].nw;
            block[i].se->equals1 = block[6].sw;
            block[i].se->equals2 = block[10].n;
            block[i].s->equals1 = block[8].nw;
            block[i].s->equals2 = block[9].ne;
            block[i].sw->equals1 = block[4].se;
            block[i].sw->equals2 = block[9].n;
            block[i].nw->equals1 = block[1].s;
            block[i].nw->equals2 = block[4].ne;
        }

        if (block[i].serial == 6)
        {
            block[i].n->equals1 = block[2].se;
            block[i].nw->equals1 = block[2].s;
            block[i].nw->equals2 = block[5].ne;
            block[i].sw->equals1 = block[5].se;
            block[i].sw->equals2 = block[10].n;
            block[i].s->equals1 = block[10].ne;
            block[i].s->equals2 = block[11].nw;
            block[i].se->equals1 = block[8].n;
        }

        if (block[i].serial == 7)
        {
            block[i].n->equals1 = block[3].sw;
            block[i].ne->equals1 = block[3].s;
            block[i].ne->equals2 = block[8].nw;
            block[i].se->equals1 = block[8].sw;
            block[i].se->equals2 = block[12].n;
            block[i].s->equals1 = block[12].nw;
        }
        if (block[i].serial == 8)
        {
            block[i].n->equals1 = block[3].se;
            block[i].n->equals2 = block[4].sw;
            block[i].ne->equals1 = block[4].s;
            block[i].ne->equals2 = block[9].nw;
            block[i].se->equals1 = block[9].sw;
            block[i].se->equals2 = block[13].n;
            block[i].s->equals1 = block[12].ne;
            block[i].s->equals2 = block[13].nw;
            block[i].sw->equals1 = block[7].se;
            block[i].sw->equals2 = block[12].n;
            block[i].nw->equals1 = block[3].s;
            block[i].nw->equals2 = block[7].ne;
        }
        if (block[i].serial == 9)
        {
            block[i].n->equals1 = block[4].se;
            block[i].n->equals2 = block[5].sw;
            block[i].ne->equals1 = block[5].s;
            block[i].ne->equals2 = block[10].nw;
            block[i].se->equals1 = block[10].sw;
            block[i].se->equals2 = block[14].n;
            block[i].s->equals1 = block[13].ne;
            block[i].s->equals2 = block[14].nw;
            block[i].sw->equals1 = block[8].se;
            block[i].sw->equals2 = block[13].n;
            block[i].nw->equals1 = block[4].s;
            block[i].nw->equals2 = block[8].ne;
        }
        if (block[i].serial == 10)
        {
            block[i].n->equals1 = block[5].se;
            block[i].n->equals2 = block[6].sw;
            block[i].ne->equals1 = block[6].s;
            block[i].ne->equals2 = block[11].nw;
            block[i].se->equals1 = block[11].sw;
            block[i].se->equals2 = block[15].n;
            block[i].s->equals1 = block[14].ne;
            block[i].s->equals2 = block[15].nw;
            block[i].sw->equals1 = block[9].se;
            block[i].sw->equals2 = block[14].n;
            block[i].nw->equals1 = block[5].s;
            block[i].nw->equals2 = block[9].ne;
        }
        if (block[i].serial == 11)
        {
            block[i].n->equals1 = block[6].se;
            block[i].nw->equals1 = block[6].s;
            block[i].nw->equals2 = block[10].ne;
            block[i].sw->equals1 = block[10].se;
            block[i].sw->equals2 = block[15].n;
            block[i].s->equals1 = block[15].nw;
        }
        if (block[i].serial == 12)
        {
            block[i].n->equals1 = block[7].se;
            block[i].n->equals2 = block[8].sw;
            block[i].ne->equals1 = block[8].s;
            block[i].ne->equals2 = block[13].nw;
            block[i].se->equals1 = block[13].sw;
            block[i].se->equals2 = block[16].n;
            block[i].s->equals1 = block[16].nw;
            block[i].nw->equals1 = block[7].s;
        }
        if (block[i].serial == 13)
        {
            block[i].n->equals1 = block[8].se;
            block[i].n->equals2 = block[9].sw;
            block[i].ne->equals1 = block[9].s;
            block[i].ne->equals2 = block[14].nw;
            block[i].se->equals1 = block[14].sw;
            block[i].se->equals2 = block[17].n;
            block[i].s->equals1 = block[16].ne;
            block[i].s->equals2 = block[17].nw;
            block[i].sw->equals1 = block[12].se;
            block[i].sw->equals2 = block[16].n;
            block[i].nw->equals1 = block[8].s;
            block[i].nw->equals2 = block[12].ne;
        }
        if (block[i].serial == 14)
        {
            block[i].n->equals1 = block[9].se;
            block[i].n->equals2 = block[10].sw;
            block[i].ne->equals1 = block[10].s;
            block[i].ne->equals2 = block[15].nw;
            block[i].se->equals1 = block[15].sw;
            block[i].se->equals2 = block[18].n;
            block[i].s->equals1 = block[17].ne;
            block[i].s->equals2 = block[18].nw;
            block[i].sw->equals1 = block[13].se;
            block[i].sw->equals2 = block[17].n;
            block[i].nw->equals1 = block[9].s;
            block[i].nw->equals2 = block[13].ne;
        }
        if (block[i].serial == 15)
        {
            block[i].n->equals1 = block[10].se;
            block[i].n->equals2 = block[11].sw;
            block[i].ne->equals1 = block[11].s;
            block[i].s->equals1 = block[18].ne;
            block[i].sw->equals1 = block[14].se;
            block[i].sw->equals2 = block[18].n;
            block[i].nw->equals1 = block[10].s;
            block[i].nw->equals2 = block[14].ne;
        }
        if (block[i].serial == 16)
        {
            block[i].n->equals1 = block[12].se;
            block[i].n->equals2 = block[13].sw;
            block[i].ne->equals1 = block[13].s;
            block[i].ne->equals2 = block[17].nw;
            block[i].se->equals1 = block[17].sw;
            block[i].nw->equals1 = block[11].s;
        }
        if (block[i].serial == 17)
        {
            block[i].n->equals1 = block[13].se;
            block[i].n->equals2 = block[14].sw;
            block[i].nw->equals1 = block[13].s;
            block[i].nw->equals2 = block[16].ne;
            block[i].ne->equals1 = block[14].s;
            block[i].ne->equals2 = block[18].nw;
            block[i].se->equals1 = block[18].sw;
            block[i].sw->equals1 = block[16].se;
        }
        if (block[i].serial == 18)
        {
            block[i].n->equals1 = block[14].se;
            block[i].n->equals2 = block[15].sw;
            block[i].ne->equals1 = block[15].s;
            block[i].nw->equals1 = block[14].s;
            block[i].nw->equals2 = block[17].ne;
            block[i].sw->equals1 = block[17].se;
        }
    }
}

// Destructor
Board::~Board()
{

    for (auto &blk : block)
    {
        delete blk.n;
        delete blk.nw;
        delete blk.ne;
        delete blk.se;
        delete blk.s;
        delete blk.sw;
    }
}
