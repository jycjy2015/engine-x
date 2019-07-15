/****************************************************************************
 Copyright (c) 2018-2019 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
 
#pragma once

#include "../Program.h"
#import <Metal/Metal.h>

CC_BACKEND_BEGIN

class ShaderModuleMTL;

/**
 * @addtogroup _metal
 * @{
 */

/**
 * A Program
 */
class ProgramMTL : public Program
{
public:
    /// @name Constructor, Destructor and Initializers
    /**
     * @param vertexShader Specifes this is a vertex shader source.
     * @param fragmentShader Specifes this is a fragment shader source.
     */
    ProgramMTL(const std::string& vertexShader, const std::string& fragmentShader);
    virtual ~ProgramMTL();
    
    /// @name Setters & Getters
    /**
     * Get vertex uniform infomation.
     * @return Vertex uniform information. Key is uniform name, Value is corresponding uniform info.
     */
    virtual const std::unordered_map<std::string, UniformInfo>& getVertexUniformInfos() const override;
    
    /**
     * Get fragment uniform information.
     * @return Fragment uniform information. Key is uniform name, Value is corresponding uniform info.
     */
    virtual const std::unordered_map<std::string, UniformInfo>& getFragmentUniformInfos() const override;
    
    /**
     * Get uniform location by name.
     * @param uniform Specifies the uniform name.
     * @return The uniform location.
     */
    virtual UniformLocation getUniformLocation(const std::string& uniform) const override;
    
    /**
     * Get vertex shader module.
     * @return Vertex shader module.
     */
    virtual ShaderModuleMTL* getVertexShader() const { return _vertexShader; }
    
    /**
     * Get fragment shader module.
     * @ Fragment shader module.
     */
    virtual ShaderModuleMTL* getFragmentShader() const { return _fragmentShader; }
    
    /**
     * Get active vertex attributes.
     * @return Active vertex attributes. key is active attribute name, Value is corresponding attribute info.
     */
    const std::unordered_map<std::string, AttributeBindInfo> getActiveAttributes() const override;
    
    /**
     * Get maximum vertex location.
     * @return Maximum vertex locaiton.
     */
    virtual int getMaxVertexLocation() const override;
    
    /**
     * Get maximum fragment location.
     * @return Maximum fragment location.
     */
    virtual int getMaxFragmentLocation() const override;

private:
    ShaderModuleMTL* _vertexShader = nullptr;
    ShaderModuleMTL* _fragmentShader = nullptr;
};

// end of _metal group
/// @}
CC_BACKEND_END