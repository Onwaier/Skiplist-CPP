//
// Created by Onwaier Lee on 2021/8/30.
// reference to https://www.shuzhiduo.com/A/1O5E2vNnd7/
//
#include <mutex>

class ReadwriteLock {
public:
    ReadwriteLock(): read_cnt(0){}

    void readLock() {
        read_mtx.lock();
        if (++read_cnt == 1)
            write_mtx.lock();

        read_mtx.unlock();
    }

    void readUnlock() {
        read_mtx.lock();
        if (--read_cnt == 0)
            write_mtx.unlock();

        read_mtx.unlock();
    }

    void writeLock() {
        write_mtx.lock();
    }

    void writeUnlock() {
        write_mtx.unlock();
    }

private:
    std::mutex read_mtx;
    std::mutex write_mtx;
    int read_cnt; // 已加读锁个数
};
