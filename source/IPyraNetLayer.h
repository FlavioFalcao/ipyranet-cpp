/*

*/

#ifndef _IPyranetLayer_h_
#define _IPyranetLayer_h_

#include "IPyraNetActivationFunction.h"

template<typename OutType>
class IPyraNetLayer {
public:
    IPyraNetLayer() : parentLayer(0), activationFunction(0) { };
    virtual ~IPyraNetLayer() { 
        parentLayer = 0; 
        if (activationFunction) 
            delete activationFunction; 
        
        activationFunction = 0;
    };

    virtual OutType getNeuronOutput(int dimensions, int* neuronLocation) = 0;

    void setParentLayer(IPyraNetLayer<OutType>* parent) { parentLayer = parent; }
    IPyraNetLayer<OutType>* getParentLayer() { return parentLayer; }

private:
    // previous (adjacent bigger) layer in the pyramid
    IPyraNetLayer<OutType>* parentLayer;
    IPyraNetActivationFunction<OutType>* activationFunction;
};

#endif // _IPyranetLayer_h_