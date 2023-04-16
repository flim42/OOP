#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

enum class Type
{
    Art, Tech
};

class Book
{
private:
    string author_;
    string Name_;
    Type BookType_;

public:
    Book(const string& author, const string& Name, Type BookType){
        author_ = author;
        Name_ = Name;
        BookType_ = BookType;
        
        }

    const Type getType() const
    {
        return BookType_;
    }
};

class Library
{
private:
    vector<Book> _library;

public:
    void addBook(const string& author, const string& Name, const Type BookType)
    {
        if (author.empty() or Name.empty())
        {
            cout << "Error" << endl;
        }
        else
        {
            Book book = Book(author, Name, BookType);
            _library.push_back(book);
        }
    }

    void countSwitch()
    {
        short countArt = 0;
        short countTech = 0;

        for (const Book& book : _library)
        {
            const Type BookType = book.getType();

            switch (BookType)
            {
            case Type::Art:
                countArt += 1;
                break;
            case Type::Tech:
                countTech += 1;
                break;
            }
        }
        cout << "Switch / Art: " << countArt << " / Tech: " << countTech << endl;
    }

    void countIf()
    {
        short countArt = 0;
        short countTech = 0;

        for (const Book& book : _library)
        {
            const Type bookType = book.getType();

            if (bookType == Type::Art)
            {
                countArt += 1;
            }
            if (bookType == Type::Tech)
            {
                countTech += 1;
            }
        }
        cout << "If / Art: " << countArt << " / Tech: " << countTech << endl;
    }
};

int main()
{
    Library library;
 
    library.addBook("111", "222", Type::Art);
    library.addBook("333", "444", Type::Tech);
    library.addBook("555", "", Type::Art);
    library.addBook("", "666", Type::Tech);

    library.countSwitch();
    library.countIf();

    return 0;
}