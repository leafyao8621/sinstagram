import sinstagram.analyzer.post_stats

if __name__ == "__main__":
    sinstagram.analyzer.post_stats.by_id(fn="out/post_stats/by_id.csv")
    sinstagram.analyzer.post_stats.by_hour(fn="out/post_stats/by_hour.csv")
    sinstagram.analyzer.post_stats.daily_active(fn="out/post_stats/daily_active.csv")
