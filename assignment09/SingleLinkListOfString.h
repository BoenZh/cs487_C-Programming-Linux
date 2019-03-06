#ifndef SINGLELINKEDLISTOFSTRING_H
#define SINGLELINKEDLISTOFSTRING_H

#include <string>

class SingleLinkedListOfString
{
    public:
        SingleLinkedListOfString();
        SingleLinkedListOfString( const std::string a[], int size );
        ~SingleLinkedListOfString();

        int size() const;
        bool empty() const;

        void addFirst( const std::string & );
        void addLast( const std::string & );
        void add( int, const std::string & );

        std::string getFirst() const;
        std::string getLast() const;
        std::string get(int) const;

        int find( const std::string & ) const;

        bool remove( const std::string & );
        void removeFirst();
        void removeLast();

        std::string toString() const;
    private:
        class Node {
        public:
            Node * next;
            std::string s;

            Node( const std::string & str ) : next(NULL), s(str) {}
        };

        Node * head;
};

#endif // SINGLELINKEDLISTOFSTRING_H
