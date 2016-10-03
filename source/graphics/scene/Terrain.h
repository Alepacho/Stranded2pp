#pragma once

#include <vector>

#include "Node.h"

#include "../Color.h"
#include "../Texture.h"
#include "../Material.h"
#include "../Vertex3D.h"

namespace gfx
{

namespace scene
{

class Terrain : public Node
{
	typedef Node super;
public:
	Terrain(unsigned terrainSize, const std::vector<float>& heightMap,
		const std::vector<gfx::Color>& colorMap, Texture* firstDetailTexture,
		Texture* secondDetailTexture, Node* parent, Scene* scene, int id = -1,
		const math::Vector3f& position = math::Vector3f(0.0f),
		const math::Vector3f& rotation = math::Vector3f(0.0f),
		const math::Vector3f& scale = math::Vector3f(1.0f));
	~Terrain();

	void onRegisterNode() override;

	void render() override;
private:
	void createTerrain(const std::vector<float>& heightMap,
		const std::vector<gfx::Color>& colorMap);
private:
	unsigned terrainSize;

	Texture* firstDetailTexture;
	Texture* secondDetailTexture;

	Material terrainMaterial;

	std::vector<Vertex3D> vertices;
	std::vector<uint32_t> indices;
};

} // namespace scene

} // namespace gfx