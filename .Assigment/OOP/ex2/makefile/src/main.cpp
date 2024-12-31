#include "document_manager.h"
#include "utils_document.h"

int main() {
    DocumentManager manager;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Document" << endl;
        cout << "2. Delete document by id" << endl;
        cout << "3. Display all document" << endl;
        cout << "4. Search document by type" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case AddDoc: {
                cout << "1. Add Book" << endl;
                cout << "2. Add Magazine" << endl;
                cout << "3. Add News" << endl;
                int typeInput;
                cin >> typeInput;
                
                if (typeInput < 1 || typeInput > 3) {
                    cout << "Invalid document type. Please enter again (1-3)." << endl;
                    break;
                }

                DocumentType type = static_cast<DocumentType>(typeInput);
                manager.addDocumentByType(type);
                break;
            }
            case DeleteDoc: {
                int id;
                cout << "Enter document's id to delete: ";
                cin >> id;
                manager.deleteDocumentById(id);
                break;
            }
            case DisplayDoc: {
                cout << "--------- All Documents ---------" << endl;
                manager.displayDocument();
                break;
            }
            case SearchByType: {
                string type;
                cout << "Enter document's type to search: ";
                cin >> type;
                manager.searchDocumentByType(type);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
