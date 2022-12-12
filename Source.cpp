#include "Test.h"

using namespace std;


int main()
{
	Test bt;
	int choice, n, key;

	int data1[] = { 12, 15, 13, 7, 9, 5, 3, 8, 11, 6, 10 };
	int data2[] = { 5, 20, 14, 17, 15, 9, 13, 7, 3, 12, 11 };
	
	while (1) {
		cout << "\n\t1. Insert Data\n\t2. Delete\n\t3. Preorder Traversal\n\t4. Inorder Traversal\n\t5. Postorder Traversal\n\t6. Find Maximum\n\t7. Exit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nTo input a pre-made dataset, enter '0'. Otherwise, enter a single datapoint...\n\nChoice: ";
			cin >> n;
			if (n == 0) {
				cout << "\nWhich Dataset Will You Use?" << endl;
				cout << "\n\t1.  { ";
				copy(begin(data1), end(data1), ostream_iterator<int>(cout, " "));
				cout << "}\n\n\t2.  { ";
				copy(begin(data2), end(data2), ostream_iterator<int>(cout, " "));
				cout << "}" << endl;

				cout << "\nChoice: ";
				cin >> n;

				if (n == 1) {
					for (int elem : data1) {
						cout << elem << " ";
						bt.insert1(elem);
					}
				}
				else if (n == 2) {
					for (int elem : data2) {
						cout << elem << " ";
						bt.insert1(elem);
					}
				}
				else {
					cout << "Please input a valid dataset! (1 or 2)" << endl;
				}
			}
			else {
				bt.insert1(n);
			}

			break;
		case 2:
			cout << "Enter element to delete: ";
			cin >> key;
			bt.Delete(key);
			break;
		case 3:
			cout << endl;
			bt.pretrav();
			break;
		case 4:
			cout << endl;
			bt.intrav();
			break;
		case 5:
			cout << endl;
			bt.posttrav();
			break;
		case 6:
			cout << endl;
			bt.Maximum();
			break;
		case 7:
			exit(0);
		default:
			cout << "Please input a valid choice!" << endl;
		}
	}
}