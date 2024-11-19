//Visualization.h
#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <vector>
#include <string>

// 학습 진척도를 시각화하는 클래스
class Visualization {
private:
    struct StudyData {
        std::string date;  // 학습 날짜 (YYYY-MM-DD 형식)
        int studyTime;     // 학습 시간 (분)
    };

    std::vector<StudyData> studyHistory; // 학습 기록 데이터

    // 날짜를 처리하는 도우미 함수
    int getWeekNumber(const std::string& date) const; // 주 번호 계산
    std::string getMonth(const std::string& date) const; // 월 계산

public:
    Visualization();

    // 학습 데이터 추가
    void addStudyData(const std::string& date, int time);

    // 학습 시간 조회
    void showDailyStudyTime(const std::string& date) const;
    void showWeeklyStudyTime(const std::string& date) const;
    void showMonthlyStudyTime(const std::string& month) const;
};

#endif