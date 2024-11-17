#include <iostream>
#include <vector>

using namespace std;

//������ �迭, ������ �迭
vector<int> arr, sorted;

//start ~ end ������ �迭�� ����ϴ� �Լ�
void printArr(int start, int end, string tag) {
    cout << tag << " array : ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

//�պ� ����(conquer, merge)
void merge(int left, int mid, int right) {
    //���� �迭, ������ �迭, ��ģ �迭�� ���� ������ ����Ŵ
    int p1 = left, p2 = mid + 1, p3 = left;

    //���� & ������ �迭 �� �ϳ��� ���Ҹ� �� ����ϸ� �ݺ��� Ż��
    //���� �迭�� ���� : left ~ mid, ������ �迭�� ���� : mid+1 ~ right
    while (p1 <= mid && p2 <= right) {
        if (arr[p1] <= arr[p2]) //���� �迭�� ���� ������ �迭�� ������ �۰ų� ����
            sorted[p3++] = arr[p1++];
        else //���� �迭�� ���� ������ �迭�� ������ ŭ
            sorted[p3++] = arr[p2++];
    }
    while (p1 <= mid) //���� �迭�� Ž������ ���� ���Ұ� �����ֳ�?
        sorted[p3++] = arr[p1++];
    while (p2 <= right) //������ �迭�� Ž������ ���� ���Ұ� �����ֳ�?
        sorted[p3++] = arr[p2++];
    //sorted �迭�� ���� ���� �ʰ� arr�� �״�� �ݿ��ϸ� �ȵȴٴ� ��⸦ ����� �����Դϴ�(Ʃ�Ϳ�)
    for (int i = left; i <= right; i++) //sorted -> arr ����
        arr[i] = sorted[i];
}

//�պ� ����(divide)
//��� �Լ��� �ƹ����� ���ذ� �ݺ������ٴ� ������� ��µ� �غ���, �ƹ�ư ������ ���� �� �����Դϴ�(Ʃ�Ϳ�)
void mergeSort(int left, int right) {
    if (left < right) { //�� ���� �� �ִٸ�
        int mid = (left + right) / 2; //��Ȯ�� �ѷ� ������
        mergeSort(left, mid); //���� �迭
        mergeSort(mid + 1, right); //������ �迭

        //���� �� �迭 ���
        //�� �κ� �Լ�ȭ �ϴ� �͵� �����ٱ� �մϴ�(Ʃ�Ϳ�)
        printArr(left, mid, "Left");
        printArr(mid + 1, right, "Right");

        merge(left, mid, right); //��ġ��

        //���� �� �迭 ���
        printArr(left, right, "Merged");
        cout << '\n';
    }
}

//�� �ڵ� �����丵 �ؼ� sort �Լ� ����ϴ°� ������ �ſ���...!(Ʃ�Ϳ�)
int main() {
    int n;

    //�Է�
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //����
    mergeSort(0, n - 1);

    //���
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
} 
