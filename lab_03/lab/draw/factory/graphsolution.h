#ifndef GRAPHSOLUTION_H
#define GRAPHSOLUTION_H

#include "absgraphfactory.h"
#include <map>
#include <string>
#include <memory>
#include "exeptions/exeptions.h"

class MainWindow;

class GraphSolution
{
public:
    typedef std::unique_ptr<AbsGraphFactory> (MainWindow::*createGraphicsCreator)();
    using CallBackMap = std::map<std::string, createGraphicsCreator>;

    bool registration(std::string id, createGraphicsCreator createGr)
    {
        return callbacks.insert(CallBackMap::value_type(id, createGr)).second;
    }

    bool check(std::string id) {return callbacks.erase(id);}

    std::unique_ptr<AbsGraphFactory> create(MainWindow *mw, std::string id)
    {
        CallBackMap::const_iterator it = callbacks.find(id);

        if (it == callbacks.end())
            throw IdError();

        std::unique_ptr<AbsGraphFactory>cr = (mw->*(it->second))();
        return cr;
     }
private:
    CallBackMap callbacks;
};

#endif // GRAPHSOLUTION_H
