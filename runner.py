import os

# build
os.system("cmake -DCMAKE_BUILD_TYPE=Release .")
os.system("cmake --build .")

dataset = [
    "karate",
    "chesapeake",
    "line49nodes",
    "dolphins",
    "rt-retweet",
    "polbooks",
    "adjnoun",
    "ia-infect-hyper",
    "ia-enron-only",
    "c-fat200-1",
    "c-fat200-2",
    "c-fat200-5",
    "squaredIdealBurn7",
    "DD244",
    "ca-netscience",
    "sanr400-0-5",
    "infect-dublin",
    "frb30-15-4",
    "c-fat500-1",
    "c-fat500-2",
    "c-fat500-5",
    "c-fat500-10",
    "bio-diseasome",
    "web-polblogs",
    "p-hat700-1",
    "p-hat700-2",
    "DD68",
    "BA-1_10_60-L5",
    "ia-crime-moreno"
]
root = "/mnt/d/Users/ale_j/Documents/inaoe/repos/bonus_alg/dataset/"

for e in dataset:
    path = root+e+".mtx"
    # path = "'"+path+"'"
    # print(e)
    os.system("./bonus_alg "+path+" bonus 1")