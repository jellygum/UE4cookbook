//#include "MyMeshComponent.h"
//#include "Engine.h"
//#include <VertexFactory.h>
//#include "DynamicMeshBuilder.h"
//#include "ConstructorHelpers.h"
//
//
//class FMyVertexBuffer : public FVertexBuffer
//{
//    public:
//        TArray<FVector> Vertices;
//
//        virtual void InitRHI() override
//        {
//            FRHIResourceCreateInfo CreateInfo;
//            VertexBufferRHI = RHICreateVertexBuffer(Vertices.Num() * sizeof(FVector), BUF_Static, CreateInfo);
//            void* VertexBufferData = RHILockVertexBuffer(VertexBufferRHI, 0, Vertices.Num() * sizeof(FVector), RLM_WriteOnly);
//            FMemory::Memcpy(VertexBufferData, Vertices.GetData(), Vertices.Num() * sizeof(FVector));
//            RHIUnlockVertexBuffer(VertexBufferRHI);
//        }
//};
//
//class FMyIndexBuffer : public FIndexBuffer
//{
//    public:
//        TArray<int32> Indices;
//
//        virtual void InitRHI() override
//        {
//            FRHIResourceCreateInfo CreateInfo;
//            IndexBufferRHI = RHICreateIndexBuffer(sizeof(int32), Indices.Num() * sizeof(int32), BUF_Static, CreateInfo);
//            void* Buffer = RHILockIndexBuffer(IndexBufferRHI, 0, Indices.Num() * sizeof(int32), RLM_WriteOnly);
//            FMemory::Memcpy(Buffer, Indices.GetData(), Indices.Num() * sizeof(int32));
//            RHIUnlockIndexBuffer(IndexBufferRHI);
//        }
//};
//
////3. CreateSceneProxy �Լ��� �����ؾ� �ϴ�, FMySceneProxy�� �ν��Ͻ��� �����Ѵ�.
////CreateSceneProxy�Լ� �Ʒ�, �ڵ带 �߰�����.
//class FMySceneProxy : public FPrimitiveSceneProxy
//{
//    public:
//        FMySceneProxy(UMyMeshComponent* Component) : FPrimitiveSceneProxy(Component),
//            Indices(Component->Indices),
//            TheMaterial(Component->TheMaterial)
//        {
//
//            VertexBuffer = FMyVertexBuffer();
//            IndexBuffer = FMyIndexBuffer();
//            for (FVector Vertex : Component->Vertices)
//            {
//                Vertices.Add(FDynamicMeshVertex(Vertex));
//            }
//        };
//
//        UPROPERTY()
//        UMaterial* TheMaterial;
//
//        virtual FPrimitiveViewRelevance GetViewRelevance(const
//            FSceneView* View) const override
//        {
//            FPrimitiveViewRelevance Result;
//            Result.bDynamicRelevance = true;
//            Result.bDrawRelevance = true;
//            Result.bNormalTranslucencyRelevance = true;
//            return Result;
//        }
//
//        virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
//        {
//            for (int32 ViewIndex = 0; ViewIndex < Views.Num();
//                ViewIndex++)
//            {
//                FDynamicMeshBuilder MeshBuilder(ERHIFeatureLevel::ES2);
//
//                if (Vertices.Num() == 0)
//                {
//                    return;
//                }
//                MeshBuilder.AddVertices(Vertices);
//                MeshBuilder.AddTriangles(Indices);
//                MeshBuilder.GetMesh(FMatrix::Identity, new FColoredMaterialRenderProxy(TheMaterial->GetRenderProxy(false), FLinearColor::Gray),
//                    GetDepthPriorityGroup(Views[ViewIndex]), true, true,
//                    ViewIndex, Collector);
//            }
//        }
//
//        //virtual void OnTransformChanged() override
//        //{
//        //    {
//        //        VertexBuffer.ReleaseResource();
//        //        IndexBuffer.ReleaseResource();
//        //    }
//        //}
//
//
//
//        virtual ~FMySceneProxy() {};
//
//
//        uint32 GetMemoryFootprint(void) const override
//        {
//            return sizeof(*this);
//        }
//
//
//        ENGINE_API virtual SIZE_T GetTypeHash() const override
//        {
//            //return Super::GetTypeHash();
//            return 1;
//        }
//
//    private:
//
//        TArray<FDynamicMeshVertex> Vertices;
//        TArray<uint32> Indices;
//
//        FMyVertexBuffer VertexBuffer;
//        FMyIndexBuffer IndexBuffer;
//};
//
//
////2. CreateSceneProxy�Լ��� �������̵��ϱ� ���� CPP���Ͽ� ������ �߰��ؾ� �Ѵ� :
//FPrimitiveSceneProxy * UMyMeshComponent::CreateSceneProxy()
//{
//    FPrimitiveSceneProxy* Proxy = NULL;
//    Proxy = new FMySceneProxy(this);
//    return Proxy;
//}
//
////5. �����ڿ� �Ʒ� �ڵ带 �߰�����
//UMyMeshComponent::UMyMeshComponent()
//{
//    static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial'"));
//    //static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial'"));
//    if (Material.Object != NULL)
//    {
//        TheMaterial = (UMaterial*)Material.Object;
//    }
//    Vertices.Add(FVector(10, 0, 0));
//    Vertices.Add(FVector(0, 10, 0));
//    Vertices.Add(FVector(0, 0, 10));
//    Indices.Add(0);
//    Indices.Add(1);
//    Indices.Add(2);
//}