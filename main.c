#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 50
#define MAX_NAME 30
#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[MAX_TITLE];
    int isBorrowed;
} Book;

typedef struct {
    int id;
    char name[MAX_NAME];
    int borrowedBookId;
} Reader;

typedef struct {
    Book books[MAX_BOOKS];
    Reader readers[MAX_BOOKS];
    int bookCount;
    int readerCount;
} Library;

void addBook(Library *library) {
    if (library->bookCount >= MAX_BOOKS) {
        printf("Limite de livros alcançado.\n");
        return;
    }

    Book *newBook = &library->books[library->bookCount++];
    newBook->id = library->bookCount;
    printf("Título do livro: ");
    getchar(); // Limpar buffer
    fgets(newBook->title, MAX_TITLE, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = '\0'; // Remover nova linha
    newBook->isBorrowed = 0;

    printf("Livro adicionado com ID %d.\n", newBook->id);
}

void addReader(Library *library) {
    if (library->readerCount >= MAX_BOOKS) {
        printf("Limite de leitores alcançado.\n");
        return;
    }

    Reader *newReader = &library->readers[library->readerCount++];
    newReader->id = library->readerCount;
    printf("Nome do leitor: ");
    getchar(); // Limpar buffer
    fgets(newReader->name, MAX_NAME, stdin);
    newReader->name[strcspn(newReader->name, "\n")] = '\0'; // Remover nova linha
    newReader->borrowedBookId = 0;

    printf("Leitor adicionado com ID %d.\n", newReader->id);
}

void borrowBook(Library *library) {
    int bookId, readerId;
    printf("ID do leitor: ");
    scanf("%d", &readerId);
    if (readerId < 1 || readerId > library->readerCount) {
        printf("Leitor não encontrado.\n");
        return;
    }

    printf("ID do livro: ");
    scanf("%d", &bookId);
    if (bookId < 1 || bookId > library->bookCount) {
        printf("Livro não encontrado.\n");
        return;
    }

    Book *book = &library->books[bookId - 1];
    Reader *reader = &library->readers[readerId - 1];

    if (book->isBorrowed) {
        printf("O livro já está emprestado.\n");
        return;
    }

    if (reader->borrowedBookId != 0) {
        printf("O leitor já possui um livro emprestado.\n");
        return;
    }

    book->isBorrowed = 1;
    reader->borrowedBookId = book->id;

    printf("Livro '%s' emprestado para %s.\n", book->title, reader->name);
}

void returnBook(Library *library) {
    int readerId;
    printf("ID do leitor: ");
    scanf("%d", &readerId);
    if (readerId < 1 || readerId > library->readerCount) {
        printf("Leitor não encontrado.\n");
        return;
    }

    Reader *reader = &library->readers[readerId - 1];
    if (reader->borrowedBookId == 0) {
        printf("O leitor não possui livros emprestados.\n");
        return;
    }

    Book *book = &library->books[reader->borrowedBookId - 1];
    book->isBorrowed = 0;
    reader->borrowedBookId = 0;

    printf("Livro '%s' devolvido com sucesso.\n", book->title);
}

void listBooks(Library *library) {
    printf("Lista de livros:\n");
    for (int i = 0; i < library->bookCount; i++) {
        Book *book = &library->books[i];
        printf("ID: %d | Título: %s | %s\n", book->id, book->title, 
               book->isBorrowed ? "Emprestado" : "Disponível");
    }
}

void listReaders(Library *library) {
    printf("Lista de leitores:\n");
    for (int i = 0; i < library->readerCount; i++) {
        Reader *reader = &library->readers[i];
        printf("ID: %d | Nome: %s | Livro Emprestado: %s\n", reader->id, reader->name,
               reader->borrowedBookId ? library->books[reader->borrowedBookId - 1].title : "Nenhum");
    }
}

int main() {
    Library library = { .bookCount = 0, .readerCount = 0 };
    int choice;

    do {
        printf("\n--- Sistema de Gerenciamento de Biblioteca ---\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Leitor\n");
        printf("3. Emprestar Livro\n");
        printf("4. Devolver Livro\n");
        printf("5. Listar Livros\n");
        printf("6. Listar Leitores\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(&library); break;
            case 2: addReader(&library); break;
            case 3: borrowBook(&library); break;
            case 4: returnBook(&library); break;
            case 5: listBooks(&library); break;
            case 6: listReaders(&library); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (choice != 0);

    return 0;
}