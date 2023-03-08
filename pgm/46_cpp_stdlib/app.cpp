class square
{
public:
   square();
   square(int s);
   ~square();

   int area();
   int perimeter();
   int getSide();

private:
   int m_side;
};

int square::getSide()
{
   return m_side;
}
square::square():
m_side(0)
{
}

square::square(int side):
m_side(side)
{
}

square::~square()
{
   m_side = 0;
}

square s1;

int main()
{

   return 0;
}
