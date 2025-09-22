/**
 * @file Layer.cpp
 *
 * @brief Definition of the class Layer
 *
 * @author LambBread from github.com
 */
#include "Layer.hpp"         
namespace rayapp   
{                 
    void Layer::OnBeforeCreate(){}
    void Layer::OnDestroy(){}
    void Layer::OnAfterDestroy(){}
    void Layer::OnEnable(){} 
    void Layer::OnDisable(){}
    int& Layer::GetStatus()  
    {                        
        return m_Status;    
    }          
    bool Layer::IsEnabled() const
    {          
        return m_Enabled;    
    }         
    std::any& Layer::GetData()
    {        
        return m_Data;    
    }       
    void Layer::Enable()
    {     
        OnEnable();    
        m_Enabled = true;    
    }     
    void Layer::Disable()
    {     
        OnDisable();    
        m_Enabled = false;   
    }    
} 
