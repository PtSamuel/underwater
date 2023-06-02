import torch
import torchvision.models as models
import torchvision.transforms as transforms
from PIL import Image
import json
import numpy as np

model = models.resnet50(pretrained=True)
model.to("cuda")
model.eval()
preprocess = transforms.Compose([
    transforms.Resize(256),
    transforms.CenterCrop(224),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
])
labels_path = "/home/samuel/flir_subscriber/src/flir_subscriber/resource/resnet_labels.txt"

def predict(capture):
    image = Image.fromarray(capture)
    input_tensor = preprocess(image).to("cuda")
    input_batch = input_tensor.unsqueeze(0)
    with torch.no_grad():
        output = model(input_batch)
        output = torch.softmax(output, dim=1)

    p, predicted_idx = torch.max(output, 1)

    with open(labels_path, 'r') as f:
        labels = json.load(f)

    predicted_label = labels[predicted_idx.item()]

    return (p, predicted_label)