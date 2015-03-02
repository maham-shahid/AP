class matrix
{
    public:
        int size;
        int m[2][2];
    public:
        matrix();;
        matrix(int x);
        void display();
        matrix operator +(matrix );
        matrix operator -(matrix );
        matrix operator *(matrix );
};