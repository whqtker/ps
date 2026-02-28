#include <iostream>
#include <deque>
#include <stack>

using namespace std;

deque<int> hq, vq; // 가로 큐, 세로 큐
int hmid = 0, vmid = 0; // 각 큐의 공유 원소 인덱스, 0-based, 원소가 없어도 일단 0
int mid = -1; // 공유 원소

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	// 원소를 삽입한 후, 공유 원소 인덱스 변경 및 공유 원소 재설정
	while (n--) {
		string cmd;
		cin >> cmd;

		// 가로 큐 원소 삽입
		if (cmd.find("hpush") != string::npos) {
			int x;
			cin >> x;
			hq.push_back(x);

			// 공유 인덱스 재설정
			hmid = (hq.size() - 1) / 2;

			// 공유 원소 재설정
			mid = hq[hmid];

			// vq 공유 원소 재설정
			if (vq.empty()) {
				vq.push_back(mid);
				vmid = (vq.size() - 1) / 2;
			}
			else {
				vq[vmid] = mid;
			}
		}
		else if (cmd.find("hpop") != string::npos) {
			if (hq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << hq.front() << "\n";
				hq.pop_front();

				// hq가 비게 된 경우 == 공유 원소 pop
				if (hq.empty()) {
					vq.erase(vq.begin() + vmid);
					vmid = (vq.size() - 1) / 2;

					// vq 또한 비게 된다면
					if (vq.empty()) {
						mid = -1;
					}
					else {
						mid = vq[vmid];
						hq.push_back(mid);
						hmid = (hq.size() - 1) / 2;
					}

				}
				else {
					hmid = (hq.size() - 1) / 2;

					mid = hq[hmid];

					if (vq.empty()) {
						vq.push_back(mid);
					}
					else {
						vq[vmid] = mid;
					}
				}
			}
		}
		else if (cmd.find("hfront") != string::npos) {
			if (hq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << hq.front() << "\n";
			}
		}
		else if (cmd.find("hback") != string::npos) {
			if (hq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << hq.back() << "\n";
			}
		}
		else if (cmd.find("hsize") != string::npos) {
			cout << hq.size() << "\n";
		}
		else if (cmd.find("vpush") != string::npos) {
			int x;
			cin >> x;
			vq.push_back(x);


			vmid = (vq.size() - 1) / 2;

			mid = vq[vmid];

			if (hq.empty()) {
				hq.push_back(mid);
				hmid = (hq.size() - 1) / 2;
			}
			else {
				hq[hmid] = mid;
			}
		}
		else if (cmd.find("vpop") != string::npos) {
			if (vq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << vq.front() << "\n";
				vq.pop_front();

				// vq가 비게 된 경우 == 공유 원소 pop
				if (vq.empty()) {
					hq.erase(hq.begin() + hmid);

					hmid = (hq.size() - 1) / 2;

					// hq 또한 비게 된다면
					if (hq.empty()) {
						mid = -1;
					}
					else {
						mid = hq[hmid];
						vq.push_back(mid);
						vmid = (vq.size() - 1) / 2;
					}
				}
				else {
					vmid = (vq.size() - 1) / 2;

					mid = vq[vmid];

					if (hq.empty()) {
						hq.push_back(mid);
					}
					else {
						hq[hmid] = mid;
					}
				}
			}
		}
		else if (cmd.find("vfront") != string::npos) {
			if (vq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << vq.front() << "\n";
			}
		}
		else if (cmd.find("vback") != string::npos) {
			if (vq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << vq.back() << "\n";
			}
		}
		else if (cmd.find("vsize") != string::npos) {
			cout << vq.size() << "\n";
		}
		else if (cmd.find("size") != string::npos) {
			if (hq.size() == 0 && vq.size() == 0) {
				cout << "0\n";
			}
			else {
				cout << hq.size() + vq.size() - 1 << "\n"; // 공유 원소 제외
			}
		}
		else if (cmd.find("empty") != string::npos) {
			if (hq.size() == 0 && vq.size() == 0) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cmd.find("middle") != string::npos) {
			if (hq.size() == 0 && vq.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << mid << "\n";
			}
		}
	}
}