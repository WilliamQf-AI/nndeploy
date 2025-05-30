
[English](README_EN.md) | 简体中文

<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="docs/image/logo.png">
    <img alt="nndeploy" src="docs/image/logo.png" width=55%>
  </picture>
</p>

<h3 align="center">
简单易用、高性能、支持多端的推理部署框架
</h3>

<p align="center">
| <a href="https://nndeploy-zh.readthedocs.io/zh/latest/"><b>文档</b></a> | <a href="docs/zh_cn/knowledge_shared/wechat.md"><b>公众号</b></a> | <a href="https://www.zhihu.com/column/c_1690464325314240512"><b>知乎</b></a> | <a href="https://discord.gg/4w2QRgn6"><b>discord</b></a> |
</p>

![Architecture](docs/image/architecture.jpg)

---

## 支持的算法

- 支持RBMGv1.4，[详情](demo/segment/README.md)
- 支持ResNet，[详情](demo/classification/README.md)
- 支持YOLOv5，[详情](demo/detect/README.md)
- 支持YOLOv6，[详情](demo/detect/README.md)
- 支持YOLOv8，[详情](demo/detect/README.md)
- 支持YOLOv11，[详情](demo/detect/README.md)
- 支持stable diffusion 1.5，完善中，[详情]()
- 支持QWen，完善中，[详情]()
- 支持SAM，完善中，[详情]()

## 特性

### 1. 简单易用

- **基于有向无环图部署模型**： 将AI算法部署抽象为有向无环图，前处理、推理、后处理各为一个节点
 
- **推理模板Infer**： 模板可处理各种模型差异，包括单/多输入输出和静态/动态形状等等
 
- **高效解决多模型组合场景**：支持`图中嵌入图`功能，将复杂任务拆分为多个独立子图，通过组合方式快速解决多模型场景问题

- **快速构建demo**：支持多种输入输出格式（图片、文件夹、视频等），通过编解码节点化实现高效通用的demo构建

### 2. 高性能

- **多种并行模式**：支持串行（按拓扑排序依次执行节点）、流水线并行（多帧场景下将不同节点绑定到不同线程和设备）、任务并行（多模型场景下挖掘并行性缩短运行时间）以及组合并行模式。

- **线程池与内存池**：通过线程池提高并发性能和资源利用率，支持CPU算子自动并行（parallel_for）提升执行效率；内存池实现高效的内存分配与释放（开发中）
  
- **一组高性能的算子**：完成后将加速您模型前后处理速度(开发中)

### 3. 支持多端

- **一套代码多端部署**：通过切换推理配置，实现一套代码即可完成模型**跨多个平台以及多个推理框架**部署，性能与原始框架一致，还可直接操作推理框架内部分配的输入输出，实现前后处理的零拷贝，提升模型部署端到端的性能

- 当前支持的推理框架如下：

  | Inference/OS                                                                     | Linux | Windows | Android | MacOS |  IOS  | developer                                                                          | remarks |
  | :------------------------------------------------------------------------------- | :---: | :-----: | :-----: | :---: | :---: | :--------------------------------------------------------------------------------- | :-----: |
  | [TensorRT](https://github.com/NVIDIA/TensorRT)                                   |   √   |    -    |    -    |   -   |   -   | [Always](https://github.com/Alwaysssssss)                                          |         |
  | [OpenVINO](https://github.com/openvinotoolkit/openvino)                          |   √   |    √    |    -    |   -   |   -   | [Always](https://github.com/Alwaysssssss)                                          |         |
  | [ONNXRuntime](https://github.com/microsoft/onnxruntime)                          |   √   |    √    |    -    |   -   |   -   | [Always](https://github.com/Alwaysssssss)                                          |         |
  | [MNN](https://github.com/alibaba/MNN)                                            |   √   |    √    |    √    |   -   |   -   | [Always](https://github.com/Alwaysssssss)                                          |         |
  | [TNN](https://github.com/Tencent/TNN)                                            |   √   |    √    |    √    |   -   |   -   | [02200059Z](https://github.com/02200059Z)                                          |         |
  | [ncnn](https://github.com/Tencent/ncnn)                                          |   -   |    -    |    √    |   -   |   -   | [Always](https://github.com/Alwaysssssss)                                          |         |
  | [coreML](https://github.com/apple/coremltools)                                   |   -   |    -    |    -    |   √   |   -   | [JoDio-zd](https://github.com/JoDio-zd)、[jaywlinux](https://github.com/jaywlinux) |         |
  | [AscendCL](https://www.hiascend.com/zh/)                                         |   √   |    -    |    -    |   -   |   -   | [CYYAI](https://github.com/CYYAI)                                                  |         |
  | [RKNN](https://www.rock-chips.com/a/cn/downloadcenter/BriefDatasheet/index.html) |   √   |    -    |    -    |   -   |   -   | [100312dog](https://github.com/100312dog)                                          |         |
  | **[default](https://github.com/nndeploy/nndeploy)**                              |   √   |    -    |    -    |   -   |   -   | [nndeploy](https://github.com/nndeploy)                                            | 内部的推理模块        |

- **内部的推理模块**：整体架构如图所示，目前后端算子以华为昇腾NPU和CPU为主，持ResNet50、YOLOv11、RMBG1.4等模型，更多介绍[default_inference.md]()

  <img src="docs/image/inference/inference_framework_arch.png">


## 快速开始

- [如何编译](docs/zh_cn/quick_start/build.md)
- [如何获取模型](docs/zh_cn/quick_start/model.md)
- [如何执行](docs/zh_cn/quick_start/example.md)


## 贡献者

<a href="https://github.com/nndeploy/nndeploy/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=nndeploy/nndeploy" />
</a>


## 联系我们
- 当前nndeploy正处于发展阶段，如果您热爱开源、喜欢折腾，不论是出于学习目的，抑或是有更好的想法，欢迎加入我们。
- 微信：titian5566 (加微信进AI推理部署交流群，请简单备注个人信息)
  
  <img src="docs/image/wechat.jpg" width="225px">


## 致谢

我们参考了以下项目：[TNN](https://github.com/Tencent/TNN)、[FastDeploy](https://github.com/PaddlePaddle/FastDeploy)、[opencv](https://github.com/opencv/opencv)、[CGraph](https://github.com/ChunelFeng/CGraph)、[CThreadPool](https://github.com/ChunelFeng/CThreadPool)、[tvm](https://github.com/apache/tvm)、[mmdeploy](https://github.com/open-mmlab/mmdeploy)、[FlyCV](https://github.com/PaddlePaddle/FlyCV)和[oneflow](https://github.com/Oneflow-Inc/oneflow)。


