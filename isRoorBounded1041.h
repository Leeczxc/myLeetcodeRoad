#ifndef LEETCODE_ISROORBOUNDED_H
#define LEETCODE_ISROORBOUNDED_H
#include "iostream"
#include "vector"
#include "map"

// û���Ƿ����ԭ��λ��
// ֻ�в�λ��ԭ���ҷ��򳯱��Ż����ѭ��
using position = std::pair<int, int>;

void turn(char& dir){
    switch (dir) {
        case 'y' : dir = 'x'; break;
        case 'x' : dir = '-y'; break;
        case '-y': dir = '-x'; break;;
        default: dir = 'y';
            break;
    }
}

bool isRobotBounded(std::string instructions) {
    char dir = 'y';
    position pos(0, 0);
    std::map<position, int> poses;
    poses[position(0, 0)];
    for(auto& c : instructions){
        if(c == 'R'){
            turn(dir);
        } else if(c == 'L'){
            for(int i = 0; i < 3; i++){
                turn(dir);
            }
        }else{
            position newPos(pos);
            switch (dir) {
                case 'y' : newPos.second += 1;
                    break;
                case 'x' : newPos.first += 1;
                    break;
                case '-y': newPos.second -= 1;
                    break;
                case '-x' : newPos.first -= 1;
                    break;
            }
            pos = newPos;
            if(poses.find(newPos) != poses.end()){
                return true;
            } else{
                poses[newPos];
            }
        }
    }
    return false;
}
#endif //LEETCODE_ISROORBOUNDED_H
