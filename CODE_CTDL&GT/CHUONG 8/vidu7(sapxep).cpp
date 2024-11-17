#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Biến kiểm tra nếu không có sự hoán đổi nào thì dừng vòng lặp
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Đổi chỗ nếu phần tử trước lớn hơn phần tử sau
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có sự hoán đổi nào, mảng đã được sắp xếp
        if (!swapped) {
            break;
        }
    }
}

// Hàm heapify cho sắp xếp vun đống
void heapify(int arr[], int n, int i) {
    int largest = i; // Khởi tạo largest là gốc
    int left = 2 * i + 1; // Chỉ số con trái
    int right = 2 * i + 2; // Chỉ số con phải

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu largest không phải là gốc
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm sắp xếp vun đống
void heapSort(int arr[], int n) {
    // Xây dựng một heap tối đa
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất các phần tử từ heap một cách tuần tự
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Di chuyển gốc đến cuối
        heapify(arr, i, 0); // Gọi heapify trên heap đã rút gọn
    }
}

// Hàm phân hoạch cho sắp xếp nhanh
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // Chỉ số của phần tử nhỏ hơn pivot
    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]); // Đổi chỗ
        }
    }
    swap(arr[i + 1], arr[high]); // Đổi chỗ pivot về vị trí đúng
    return (i + 1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Tạo các mảng tạm
    int L[n1], R[n2];
    // Sao chép dữ liệu vào các mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // Hợp nhất các mảng tạm
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp hòa nhập
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tránh tràn số nguyên
        // Sắp xếp nửa trái
        mergeSort(arr, left, mid);
        // Sắp xếp nửa phải
        mergeSort(arr, mid + 1, right);
        // Hợp nhất hai nửa
        merge(arr, left, mid, right);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100], n, chon;
    
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do { system("cls");
        cout << "Chon thuat toan sap xep:\n";
        cout << "1. Sap xep lua chon (Selection Sort)\n";
        cout << "2. Sap xep chen (Insertion Sort)\n";
        cout << "3. Sap xep noi bot (Bubble Sort)\n";
        cout << "4. Sap xep vun dong (Heap Sort)\n";
        cout << "5. Sap xep nhanh (Quick Sort)\n";
        cout << "6. Sap xep hoa nhap (Merge Sort)\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> chon;

        switch (chon) {
            case 1:
                selectionSort(arr, n);
                cout << "Mang sau khi sap xep lua chon: ";
                printArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                cout << "Mang sau khi sap xep chen: ";
                printArray(arr, n);
                break;
            case 3:
                bubbleSort(arr, n);
                cout << "Mang sau khi sap xep noi bot: ";
                printArray(arr, n);
                break;
            case 4:
                heapSort(arr, n);
                cout << "Mang sau khi sap xep vun dong: ";
                printArray(arr, n);
                break;
            case 5:
                quickSort(arr, 0, n - 1);
                cout << "Mang sau khi sap xep nhanh: ";
                printArray(arr, n);
                break;
            case 6:
                mergeSort(arr, 0, n - 1);
                cout << "Mang sau khi sap xep hoa nhap: ";
                printArray(arr, n);
                break;
            case 0:
                cout << "Thoat!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        } system("pause");
    } while (chon != 0);

    return 0;
}
