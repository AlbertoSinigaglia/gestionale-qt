//helloooooooooooo


//
//ciccccccccccccio
#ifndef CSVPARSER_CSVINTERFACE_H
#define CSVPARSER_CSVINTERFACE_H

#include <string>
#include <vector>
#include <map>

class CSVInterface{
public:
    virtual ~CSVInterface() = default;
    [[nodiscard]] virtual std::map<std::string, std::string>toMap() const = 0;
};
#endif //CSVPARSER_CSVINTERFACE_H
