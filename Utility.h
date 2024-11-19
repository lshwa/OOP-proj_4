#ifndef UTILITY_H
#define UTILITY_H

#include <string>

// 공용 유틸리티 함수를 위한 헤더
namespace Utility {
    // 문자열을 날짜 형식으로 변환하는 함수
    std::string formatDateString(const std::string& dateString);

    // 입력 받은 시간 문자열을 분으로 변환하는 함수
    int convertTimeToMinutes(const std::string& timeString);
}

#endif