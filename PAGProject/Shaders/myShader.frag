#version 450 core

struct Material {
	sampler2D texture_diffuse1;
	sampler2D texture_diffuse2;
	sampler2D texture_diffuse3;
	sampler2D texture_specular1;
	sampler2D texture_specular2;
    float shininess;
}; 

struct MyMaterial {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;    
    float shininess;
}; 

struct DirLight {
    vec3 direction;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;
uniform Material material;
uniform MyMaterial mMaterial;

out vec4 FragColor;
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;


vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);


void main()
{    
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
        result += CalcPointLight(pointLight, norm, FragPos, viewDir);    
	   result += CalcSpotLight(spotLight, norm, FragPos, viewDir);   
    
    FragColor = vec4(result, 1.0f);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), (material.shininess + mMaterial.shininess));

    vec3 ambient = light.ambient * (vec3(texture(material.texture_diffuse1, TexCoord)) + mMaterial.ambient);
    vec3 diffuse = light.diffuse * diff * (vec3(texture(material.texture_diffuse1, TexCoord)) + mMaterial.diffuse);
    vec3 specular = light.specular * spec * (vec3(texture(material.texture_specular1, TexCoord)) + mMaterial.specular);
    return (ambient + diffuse + specular);
}


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), (material.shininess + mMaterial.shininess));
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    vec3 ambient = light.ambient * (vec3(texture(material.texture_diffuse1, TexCoord)) + mMaterial.ambient);
    vec3 diffuse = light.diffuse * diff * (vec3(texture(material.texture_diffuse1, TexCoord)) + mMaterial.diffuse);
    vec3 specular = light.specular * spec * (vec3(texture(material.texture_specular1, TexCoord)) + mMaterial.specular);
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}


vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), (material.shininess + mMaterial.shininess));
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    vec3 ambient = light.ambient * (vec3(texture(material.texture_diffuse1, TexCoord)) + mMaterial.ambient);
    vec3 diffuse = light.diffuse * diff * (vec3(texture(material.texture_diffuse1, TexCoord)) + mMaterial.diffuse);
    vec3 specular = light.specular * spec * (vec3(texture(material.texture_specular1, TexCoord)) + mMaterial.specular);
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}


