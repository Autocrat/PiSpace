#ifndef BULLET_H
#define BULLET_H

#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h> 
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::sca

#ifndef RAD2DEG
#define RAD2DEG(x) ((x) * 57.2957795f)
#endif

class Bullet
{
private:
    b2Body *m_pBody;
    b2World& m_world;
    float32 m_radius;

    static const glm::mat4 m_projMat;
    static GLuint m_shaderProgram;


    //only using 1 vertex buffer for this object
    GLuint m_vertexBufferHandleArray[1];    
    GLuint m_colorBufferHandleArray[1];    


    GLuint m_indexBuffer;
    GLuint m_numIndices;
    glm::vec3 m_rotateAxis;


    void SetActive();
    void SetInactive();
    
    uint32 m_timestamp;
public:
    Bullet(b2World& world);
    ~Bullet();

    void Fire(const b2Transform& xf);
    void Draw();
    void Update();
};

#endif