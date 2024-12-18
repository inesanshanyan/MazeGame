#pragma once 

class AbstractController {
public:
    virtual ~AbstractController() = default;
    virtual void execute() = 0;
    
};
